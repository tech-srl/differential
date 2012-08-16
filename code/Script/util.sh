filename=$1
patched_filename=$2
clear="-clear=false"
preprocess="-preprocess=false"
x0="-x0=false"
tag_equality="-tag_equality=false"
diff_points="-diff_points=false"
ret_guard="-ret_guard=false"
inline="-inline=false"
asserts="-asserts=false"

function ParseUccCommandLine {
    while [[ $# > 0 ]] ; do
        case $1 in
            -clear=*)     clear=$1 ;        shift 1 ;;
            -prep=*)      preprocess=$1 ;   shift 1 ;;
            -x0=*)        x0=$1 ;           shift 1 ;;
            -eq=*)        tag_equality=$1 ; shift 1 ;;
            -diffp=*)     diff_points=$1 ;  shift 1 ;;
            -ret=*)       ret_guard=$1 ;    shift 1 ;;
            -inline=*)    inline=$1 ;       shift 1 ;;
            -asserts=*)   asserts=$1 ;       shift 1 ;;
            *)                              shift 1 ;;
        esac
    done
    echo "Clear Identical Functions? : [$clear]"
    echo "Preprocess? : [$preprocess]"
    echo "Inline? : [$inline]"
    echo "Preserve Initial Values? (i.e. x = x0) : [$x0]"
    echo "Create Tag Equality? (i.e. x = x') : [$tag_equality]"
    echo "Create Diff Points? : [$diff_points]"
    echo "Add Assertions? (i.e. assert(x' == x)) : [$asserts]"
    echo "Replace return With Guard? : [$ret_guard]"
}

manager="-m=ppl"
canon_point="-c_p=join"
canon_strategy="-c_s=equiv"

function ParseAnalyzerCommandLine {
    while [[ $# > 0 ]] ; do
        case $1 in
            *-m=*) manager=$1 ;             shift 1 ;;
            *-c_p=*) canon_point=$1 ;       shift 1 ;; 
            *-c_s=*) canon_strategy=$1 ;    shift 1 ;;  
            *)                              shift 1 ;;
        esac
    done
    echo "Domain Manager : [$manager]"
    echo "Canonization Point : [$canon_point]"
    echo "Canonization Strategy : [$canon_strategy]"
}

function Preprocess {
    if [[ $preprocess == $1 ]] 
        then
            echo Preprocessing $1...
            gcc -E $1 > prep.$1
            if [ $1 == $filename ] 
                then
                    filename=prep.$1
                else
                    patched_filename=prep.$1
            fi
    fi
}

function Inline {
    if [[ $inline == $1 ]] 
        then
            echo Inlining $1...
            ucc -i $1
            if [ $1 == $filename ] 
                then
                    filename=inlined.$1
                else
                    patched_filename=inlined.$1
            fi
    fi
}
