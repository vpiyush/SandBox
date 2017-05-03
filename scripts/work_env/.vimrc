set nocompatible         " Use Vim defaults (much better!)
set bs=indent,eol,start         " allow backspacing over everything in insert mode
set ai                  " always set autoindenting on
"set backup             " keep a backup file
set viminfo='20,\"50    " read/write a .viminfo file, don't store more
                        " than 50 lines of registers
set history=50          " keep 50 lines of command line history
set ruler               " show the cursor position all the time
set ic
"set lazyredraw
set smarttab
set si
set wrap
set tabstop=4
set shiftwidth=4
set softtabstop=4
set et
set rnu
set browsedir=buffer
set wildmenu
set wildmode=longest:full,full
set wildignore=*.o,*~,*.pyc
set wildignore+=*/tmp/*,*.so,*.swp,*.zip,*.tgz,*.hlp
set wildcharm=<C-Z>
nnoremap <F9> :b <C-Z>
nnoremap <F6> :set nonu!<CR>
nnoremap ff zf<s-%>
set cmdheight=1
set hid
set nobackup
set nowb
set noswapfile
set showcmd
set showmatch
set laststatus=2
"set so=999   " always keep the cursor line in the middle
set ttimeoutlen=50   " reduce the time when switching from insert mode to normal mode
"set title titlestring=%<%f\ %([%{Tlist_Get_Tagname_By_Line()}]%)
set undofile
set undodir=/tmp
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" The following are examples of different formats supported.
" Keep Plugin commands between vundle#begin/end.
" plugin on GitHub repo
Plugin 'tpope/vim-fugitive'
" plugin from http://vim-scripts.org/vim/scripts.html
Plugin 'L9' 
Plugin 'majutsushi/tagbar'
Plugin 'TagHighlight'
Plugin 'easymotion/vim-easymotion'
"Plugin 'flazz/vim-colorschemes'
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'
" Git plugin not hosted on GitHub
"Plugin 'ctrlp'
Plugin 'vimwiki'
"Plugin 'git://git.wincent.com/command-t.git'
" git repos on your local machine (i.e. when working on your own plugin)
"Plugin 'file:///home/gmarik/path/to/plugin'
" The sparkup vim script is in a subdirectory of this repo called vim.
" Pass the path to set the runtimepath properly.
Bundle "ctrlp.vim"
" Utility
Bundle "repeat.vim"
Bundle "file-line"
Bundle "Align"
" FuzzyFinder
Plugin 'jeetsukumaran/vim-markology'
Plugin 'scrooloose/nerdcommenter'
" Avoid a name conflict with L9
"Plugin 'user/L9', {'name': 'newL9'}

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
   " Put your non-Plugin stuff after this line
let g:airline#extensions#tabline#enabled = 0
"let g:airline#extensions#tabline#left_sep = '▶'
"let g:airline#extensions#syntastic#enabled = 1
"let g:airline#extensions#tabline#tab_nr_type = 1
let g:airline#extensions#tabline#buffer_nr_show = 1
let g:airline#extensions#tabline#fnamemod = ':t'
"let g:airline#extensions#tabline#close_symbol = 'X'
let g:airline#extensions#default#section_truncate_width = {
      \ 'b': 79,
      \ 'x': 60,
      \ 'y': 88,
      \ 'z': 10,
      \ 'warning' : 0,
      \}
let g:airline_section_warning = '%b,0x%-8B'
let g:airline_powerline_fonts = 2
let Tlist_Use_Right_Window = 1
let g:ctrlp_max_files = 0
let g:ctrlp_cmd = 'CtrlP'
" Search from current directory instead of project root
"let ex_file=findfile("exports.sh", ".;")
"let ex_pre=matchstr(ex_file, ".*/")
let g:ctrlp_working_path_mode = 'ra'
let g:ctrlp_root_markers = ['.ctrlp']
let g:ctrlp_clear_cache_on_exit = 0
let g:ctrlp_cache_dir = $HOME.'/.cache/ctrlp'
"
map <F3> :NERDTreeFind<CR>
map <F2> :NERDTreeToggle<CR>
map <F4> :TagbarToggle<CR>
inoremap <C-E> <C-X><C-E>
set incsearch
nnoremap <silent> <F5> :let _s=@/<Bar>:%s/\s\+$//e<Bar>:let @/=_s<Bar>:nohl<CR>
if has("cscope") && filereadable("/usr/bin/cscope")
   set csprg=/usr/bin/cscope
   set csto=0
   set cst
   set nocsverb
   " add any database in current directory
   if filereadable("cscope.out")
      cs add cscope.out
   " else add database pointed to by environment
   elseif $CSCOPE_DB != ""
      cs add $CSCOPE_DB
   else
      let cscope_file=findfile("cscope.out", ".;")
      let cscope_pre=matchstr(cscope_file, ".*/")
  "echo cscope_file
     if !empty(cscope_file) && filereadable(cscope_file)
           exe "cs add" cscope_file cscope_pre
     endif
   endif
   set csverb
endif



if has('cscope')
  set cscopetag cscopeverbose

 " if has('quickfix')
    "set cscopequickfix=s-,c-,d-,i-,t-,e-  "this option disable the long
    "listing of search results and dirctly jump to the first result
 " endif

  cnoreabbrev csa cs add
  cnoreabbrev csf cs find
  cnoreabbrev csk cs kill
  cnoreabbrev csr cs reset
  cnoreabbrev css cs show
  cnoreabbrev csh cs help

  "command -nargs=0 Cscope cs add $VIMSRC/src/cscope.out $VIMSRC/src
endif

nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>

set tags+=tags;/
map <Leader> <Plug>(easymotion-prefix)
nmap s <Plug>(easymotion-s2)

if exists("cscope_pre")
	let $cscope_path = cscope_pre
endif

nmap <F12> :!find $cscope_path -iname '*.c' -o -iname '*.cpp' -o -iname '*.h' > $cscope_path/cscope.files<CR>
  \:!cscope -b -i $cscope_path/cscope.files -f $cscope_path/cscope.out<CR>
  \:cs reset<CR>

set mouse=nicr
nnoremap <silent> <Leader>+ :exe "vertical resize +2" <CR>
nnoremap <silent> <Leader>- :exe "vertical resize -2" <CR>
"colorscheme wombat256
