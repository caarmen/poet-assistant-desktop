:: Copyright (c) 2022 - present Carmen Alvarez
::
:: This file is part of Poet Assistant.
::
:: Poet Assistant is free software: you can redistribute it and/or modify
:: it under the terms of the GNU General Public License as published by
:: the Free Software Foundation, either version 3 of the License, or
:: (at your option) any later version.
::
:: Poet Assistant is distributed in the hope that it will be useful,
:: but WITHOUT ANY WARRANTY; without even the implied warranty of
:: MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
:: GNU General Public License for more details.
::
:: You should have received a copy of the GNU General Public License
:: along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.

if "%QT_HOME%"=="" (
    ECHO QT_HOME environment variable must be defined
    exit /b
)
if "%QT_IFW_HOME%"=="" (
    ECHO QT_IFW_HOME environment variable must be defined
    exit /b
)
set /P version=<deploy\version.txt

set project_folder=%CD%
call %QT_HOME%\mingw_64\bin\qtenv2.bat

:: the qtenv2.bat script changes directories. We need to change back
cd %project_folder%

set app_folder=%project_folder%\app
set output_folder=%app_folder%\build\out

echo Preparing installer config...
call :writeVersionFile deploy\config\config.xml.template deploy\config\config.xml %version%
call :writeVersionFile deploy\packages\com.poetassistant\meta\package.xml.template deploy\packages\com.poetassistant\meta\package.xml %version%

echo Compiling...

qmake -recursive VERSION=%version% PoetAssistant.pro

:: The release makefile looks for the generated translation file in the debug folder.
:: Make just this target before making the release
cd %app_folder%
mingw32-make -f Makefile.Debug debug/PoetAssistant_en_US.qm
cd %project_folder%

mingw32-make release

windeployqt --qmldir=%app_folder%\resources --qmlimport=%app_folder%\resources  %output_folder%\PoetAssistant.exe

echo Building archive...
copy deploy\config\icon.ico %output_folder%\icon.ico
set installer_file_base=PoetAssistantInstaller
set installer_file_exe=%installer_file_base%.exe
set installer_file_zip=PoetAssistant-win-installer-%version%.zip
set zip_file=PoetAssistant-win-portable-%version%.zip
cd %output_folder%
if exist %zip_file% del %zip_file%
if exist %installer_file_exe% del %installer_file_exe%
if exist %installer_file_zip% del %installer_file_zip%
zip -r %zip_file% *
cd %project_folder%
echo created %zip_file%

set package_data_dir=deploy\packages\com.poetassistant\data
if exist %package_data_dir% rd /s /q %package_data_dir%
md %package_data_dir%
copy %output_folder%\%zip_file% %package_data_dir%

echo Creating installer...
%QT_IFW_HOME%\bin\binarycreator.exe --offline-only -c deploy/config/config.xml -p deploy/packages %output_folder%\%installer_file_base%
cd %output_folder%
zip %installer_file_zip% %installer_file_exe%
cd %project_folder%
echo Created %zip_file% and %installer_file_zip%

EXIT /B %ERRORLEVEL%
:: ---------------------------
:: FUNCTIONS HERE
:: ---------------------------
:writeVersionFile
SET template_file=%~1
SET output_file=%~2
SET version=%~3
SETLOCAL EnableDelayedExpansion

DEL %output_file%

For /f "tokens=* delims= " %%a in (%template_file%) do (
    SET line=%%a
    SET line=!line:__VERSION__=%version%!
    echo !line!>>%output_file%
)
ENDLOCAL
EXIT /B 0
