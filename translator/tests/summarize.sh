#!/bin/bash
#*******************************************************************************
# Copyright 2019-2020 FUJITSU LIMITED
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#*******************************************************************************/
LIST=`find pattern -name "*.cpp"`
#LIST=`find pattern/mov -name "*.cpp"`

for i in ${LIST} ; do
    TP_BASE=`echo ${i} | sed -e "s/\.cpp//"`

    if [ -f ${TP_BASE}.check.ng ] ; then
	grep NG ${TP_BASE}.check.ng
	if [ $? != 0 ] ; then
	    echo "NOT FOUND:${TP_BASE}"
	fi
    elif [ -f ${TP_BASE}.check ] ; then
	grep OK ${TP_BASE}.check
	if [ $? != 0 ] ; then
	    echo "NOT FOUND:${TP_BASE}"
	fi
    else
	echo "NO:${TP_BASE}"
    fi
done
