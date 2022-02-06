# Copyright (c) 2022 - present Carmen Alvarez
#
# This file is part of Poet Assistant.
#
# Poet Assistant is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# Poet Assistant is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with Poet Assistant.  If not, see <http://www.gnu.org/licenses/>.

if [[ ! -v QT_HOME ]]
then 
    echo "QT_HOME environment variable must be defined"
    exit
fi

version=$(cat deploy/version.txt)

program_file_name=PoetAssistant
temp_folder=$(mktemp --directory -t poet-assistant-XXXXXXXXXX)

function build {
    qmake VERSION=$version
    make
}

function copyProgram {
    cp build/out/$program_file_name $temp_folder
}

function updateRpath {
    copied_program=$temp_folder/$program_file_name
    chrpath -r '$ORIGIN/dependencies/lib' $copied_program
}

function copyDependencies {
    echo "Copying dependencies..."
    libs=( \
        libQt6Concurrent.so.6 \
        libQt6Core.so.6 \
        libQt6DBus.so.6 \
        libQt6Gui.so.6 \
        libQt6Network.so.6 \
        libQt6OpenGL.so.6 \
        libQt6Qml.so.6 \
        libQt6QmlModels.so.6 \
        libQt6QmlWorkerScript.so.6 \
        libQt6Quick.so.6 \
        libQt6QuickControls2.so.6 \
        libQt6QuickControls2Impl.so.6 \
        libQt6QuickDialogs2.so.6 \
        libQt6QuickDialogs2QuickImpl.so.6 \
        libQt6QuickDialogs2Utils.so.6 \
        libQt6QuickLayouts.so.6 \
        libQt6QuickTemplates2.so.6 \
        libQt6Sql.so.6 \
        libQt6Svg.so.6 \
        libQt6Widgets.so.6 \
        libQt6XcbQpa.so.6 \
        libicudata.so.56 \
        libicui18n.so.56 \
        libicuuc.so.56 \
    )
    
    plugin_files=( \
        platformthemes/libqgtk3.so \
        sqldrivers/libqsqlite.so \
        imageformats/libqsvg.so \
        platforms/libqxcb.so \
        xcbglintegrations/libqxcb-glx-integration.so \
    )
    
    qt_quick_paths=( \
        Dialogs \
        Layouts \
        Templates \
        Window \
        libqtquick2plugin.so \
    )
    
    qt_theme_paths=(\
        Basic \
        Fusion \
        Imagine \
        Material \
        impl \
        Universal \
        libqtquickcontrols2plugin.so \
        qmldir \
    ) \
    
    labs_folders=(\
        platform \
    )
    
    qt_qml_folders=(\
        WorkerScript \
    )
    qt_source_folder=$QT_HOME/6.2.3/gcc_64
    
    dependencies_folder=$temp_folder/dependencies
    mkdir -p $dependencies_folder
    mkdir -p $dependencies_folder/lib
    mkdir -p $dependencies_folder/plugins
    mkdir -p $dependencies_folder/qml/QtQuick/Controls
    mkdir -p $dependencies_folder/qml/Qt/labs
    mkdir -p $dependencies_folder/qml/QtQml
    
    for lib in ${libs[@]}
    do
        cp $qt_source_folder/lib/$lib $dependencies_folder/lib/.
    done
    
    for plugin_file in ${plugin_files[@]}
    do
        mkdir -p $(dirname $dependencies_folder/plugins/$plugin_file) && cp $qt_source_folder/plugins/$plugin_file $dependencies_folder/plugins/$plugin_file
    done
    
    for qt_quick_path in ${qt_quick_paths[@]}
    do
        cp -pr $qt_source_folder/qml/QtQuick/$qt_quick_path $dependencies_folder/qml/QtQuick/.
    done
    
    for qt_theme_path in ${qt_theme_paths[@]}
    do
        cp -pr $qt_source_folder/qml/QtQuick/Controls/$qt_theme_path $dependencies_folder/qml/QtQuick/Controls/.
    done
    
    for labs_folder in ${labs_folders[@]}
    do
        cp -pr $qt_source_folder/qml/Qt/labs/$labs_folder $dependencies_folder/qml/Qt/labs/.
    done
    
    for qt_qml_folder in ${qt_qml_folders[@]}
    do
        cp -pr $qt_source_folder/qml/QtQml/$qt_qml_folder $dependencies_folder/qml/QtQml/.
    done
}

function createArchive {
    output_file=build/out/PoetAssistant-linux-$version.tgz
    echo "Creating ${output_file}..."
    rm -f $output_file
    tar czf $output_file -C $temp_folder $program_file_name dependencies
    echo "created $output_file"
}

build
copyDependencies
copyProgram
updateRpath
createArchive
