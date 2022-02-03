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

set current_folder=%CD%
call %QT_HOME%\mingw_64\bin\qtenv2.bat

:: the qtenv2.bat script changes directories. We need to change back
cd %current_folder%

qmake

:: The release makefile looks for the generated translation file in the debug folder.
:: Make just this target before making the release
mingw32-make -f Makefile.Debug debug/PoetAssistant_en_US.qm

mingw32-make release

set output_folder=build\out
copy deploy\config\icon.ico %output_folder%\icon.ico

windeployqt --qmldir=. --qmlimport=. %output_folder%\PoetAssistant.exe

echo Building archive...
set installer_file=PoetAssistantInstaller
set zip_file=PoetAssistant.zip
cd %output_folder%
if exist %zip_file% del %zip_file%
if exist %installer_file%.exe del %installer_file%.exe
zip -r %zip_file% *
cd ..\..
echo created %zip_file%

set package_data_dir=deploy\packages\com.poetassistant\data
if not exist %package_data_dir% md %package_data_dir%
copy %output_folder%\%zip_file% %package_data_dir%

echo Creating installer...
%QT_IFW_HOME%\bin\binarycreator.exe --offline-only -c deploy/config/config.xml -p deploy/packages %output_folder%\%installer_file%
