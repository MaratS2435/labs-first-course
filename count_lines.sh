count_lines() {
    local dir="$1"
    local count=0
    local total_length=0

    for entry in "$dir"/*; do
        if [[ -f "$entry" ]]; then
            if [[ "$entry" == *".h" ]] || [[ "$entry" == *".cpp" ]]; then
                local lines=$(wc -l < "$entry")
                count=$((count + lines))
                total_length=$((total_length + lines + 1))
            fi
        elif [[ -d "$entry" ]]; then
            count_lines "$entry"
        fi
    done

    echo "Директория: $dir"
    echo "Число строк: $count"
    echo "Суммарная длина (в строках): $total_length"
    echo
}

directory="./test21"  # Замените на нужный путь к директории
count_lines "$directory"

