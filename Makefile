#================================[[ beg-code ]]================================#
include /usr/local/sbin/make_prepare



#===(user defined)=========================================#
# basename of executable, header, and all code files
NAME_BASE  = kairos
# additional standard and outside libraries
LIB_MINE   = ${LIB_OPENGL} -lXext
# directory for production code, no trailing slash
INST_DIR   = /usr/local/bin



#===(post-processing)======================================#
# create a rule for...
#    install_prep       :
#    remove_prep        :


#===(master template)======================================#
include /usr/local/sbin/make_program



#===(post-processing)======================================#
# create a rule for...
#    install_post       :
#    remove_post        :



#================================[[ end-code ]]================================#
