#!/bin/bash
# Script to generate module_info.h from config file

CONFIG_FILE=$1
OUTPUT_FILE=$2

if [ ! -f "$CONFIG_FILE" ]; then
    echo "Config file not found: $CONFIG_FILE"
    exit 1
fi

# Source the config file
source "$CONFIG_FILE"

# Generate header file
cat > "$OUTPUT_FILE" << EOF
/* Auto-generated from hello_module.conf */
#ifndef MODULE_INFO_H
#define MODULE_INFO_H

#define MODULE_DESC "$MODULE_DESCRIPTION"
#define MODULE_AUTH "$MODULE_AUTHOR"
#define MODULE_VER "$MODULE_VERSION"

#endif /* MODULE_INFO_H */
EOF

echo "Generated $OUTPUT_FILE from $CONFIG_FILE"

