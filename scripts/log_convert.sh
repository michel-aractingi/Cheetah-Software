#!/bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo -e "Dir is ${DIR}"
export PYTHONPATH=${DIR}/../lcm-types/python/:${DIR}:${DIR}/lcm-log2smat/python:${PYTHONPATH}
echo -e "Python path is ${PYTHONPATH}"
python -m lcmlog2smat.log_to_smat $1 -k -o $2
