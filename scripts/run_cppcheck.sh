#!/usr/bin/env bash

set -euo pipefail
IFS=$'\n\t'

###############################################################################
# Run cppcheck on all sources (for usage in CIs)
# If you develop for this project, please use `make cppcheck`.
###############################################################################

cd "$(dirname "$0")/.."
source scripts/utils.sh

print_important "Run cppcheck on all source files"
print_info "Will only print warnings"

cppcheck --enable=performance,warning,portability,information,missingInclude \
	--error-exitcode=1 \
	--inline-suppr     \
	-q                 \
	-Isrc              \
	-j2                \
	./src

print_success "No issues found! Great! :-)"
