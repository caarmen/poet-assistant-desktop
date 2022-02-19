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

version=$(cat deploy/version.txt)

project_dir=`pwd`
output_dir=$project_dir/app/build/out

cd lib/qtspeech/src/tts
qmake 'DEFINES+="__cpp_lib_hypot=0"'
cd $project_dir

qmake VERSION=$version
make

temp_folder=$(mktemp -d -t poet-assistant-XXXXXXXXXX)
cp -pr $output_dir/PoetAssistant.app $temp_folder
macdeployqt $temp_folder/PoetAssistant.app/ -qmldir=app/resources/ -qmlimport=app/resources/
find $temp_folder/PoetAssistant.app/ -name "*.dSYM"|xargs rm -rf
hdiutil create $output_dir/PoetAssistant.dmg -ov -volname "Poet Assistant" -fs HFS+ -srcfolder $temp_folder
target_dmg_file=$output_dir/PoetAssistant-mac-$version.dmg
hdiutil convert $output_dir/PoetAssistant.dmg -format UDZO -o $target_dmg_file
rm $output_dir/PoetAssistant.dmg

echo "created $target_dmg_file"
