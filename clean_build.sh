exist_build=0
[[ -d ./build ]] && exist_build=1
if [[ $exist_build -eq 1 ]]; then
    echo "Clean build"
    rm -rf ./build
    mkdir -p ./build
fi
cmake -B ./build && make -C ./build