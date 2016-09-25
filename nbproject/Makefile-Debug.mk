#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=Cygwin-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/AbstractKMP.o \
	${OBJECTDIR}/AbstractKMP/Area.o \
	${OBJECTDIR}/AbstractKMP/Camera.o \
	${OBJECTDIR}/AbstractKMP/CheckPoints.o \
	${OBJECTDIR}/AbstractKMP/EnemyRoutes.o \
	${OBJECTDIR}/AbstractKMP/GliderRoutes.o \
	${OBJECTDIR}/AbstractKMP/ItemRoutes.o \
	${OBJECTDIR}/AbstractKMP/KartPoints.o \
	${OBJECTDIR}/AbstractKMP/Objects.o \
	${OBJECTDIR}/AbstractKMP/RespawnPoints.o \
	${OBJECTDIR}/AbstractKMP/Routes.o \
	${OBJECTDIR}/AbstractKMP/StageInfo.o \
	${OBJECTDIR}/CommonTypes.o \
	${OBJECTDIR}/KMP.o \
	${OBJECTDIR}/Libs/EndianBinaryIO.o \
	${OBJECTDIR}/Libs/pugixml.o \
	${OBJECTDIR}/Sections/AreaPoint.o \
	${OBJECTDIR}/Sections/Camera.o \
	${OBJECTDIR}/Sections/CannonPoint.o \
	${OBJECTDIR}/Sections/CheckPath.o \
	${OBJECTDIR}/Sections/CheckPoint.o \
	${OBJECTDIR}/Sections/CourseSect.o \
	${OBJECTDIR}/Sections/EnemyPath.o \
	${OBJECTDIR}/Sections/EnemyPoint.o \
	${OBJECTDIR}/Sections/GliderPath.o \
	${OBJECTDIR}/Sections/GliderPoint.o \
	${OBJECTDIR}/Sections/GlobalObject.o \
	${OBJECTDIR}/Sections/ItemPath.o \
	${OBJECTDIR}/Sections/ItemPoint.o \
	${OBJECTDIR}/Sections/JugemPoint.o \
	${OBJECTDIR}/Sections/KartPoint.o \
	${OBJECTDIR}/Sections/MissionPoint.o \
	${OBJECTDIR}/Sections/PointInfo.o \
	${OBJECTDIR}/Sections/StageInfo.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=-mcmodel=medium
CXXFLAGS=-mcmodel=medium

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-LLibs

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kmpedit.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kmpedit.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kmpedit ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/AbstractKMP.o: AbstractKMP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP.o AbstractKMP.cpp

${OBJECTDIR}/AbstractKMP/Area.o: AbstractKMP/Area.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/Area.o AbstractKMP/Area.cpp

${OBJECTDIR}/AbstractKMP/Camera.o: AbstractKMP/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/Camera.o AbstractKMP/Camera.cpp

${OBJECTDIR}/AbstractKMP/CheckPoints.o: AbstractKMP/CheckPoints.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/CheckPoints.o AbstractKMP/CheckPoints.cpp

${OBJECTDIR}/AbstractKMP/EnemyRoutes.o: AbstractKMP/EnemyRoutes.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/EnemyRoutes.o AbstractKMP/EnemyRoutes.cpp

${OBJECTDIR}/AbstractKMP/GliderRoutes.o: AbstractKMP/GliderRoutes.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/GliderRoutes.o AbstractKMP/GliderRoutes.cpp

${OBJECTDIR}/AbstractKMP/ItemRoutes.o: AbstractKMP/ItemRoutes.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/ItemRoutes.o AbstractKMP/ItemRoutes.cpp

${OBJECTDIR}/AbstractKMP/KartPoints.o: AbstractKMP/KartPoints.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/KartPoints.o AbstractKMP/KartPoints.cpp

${OBJECTDIR}/AbstractKMP/Objects.o: AbstractKMP/Objects.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/Objects.o AbstractKMP/Objects.cpp

${OBJECTDIR}/AbstractKMP/RespawnPoints.o: AbstractKMP/RespawnPoints.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/RespawnPoints.o AbstractKMP/RespawnPoints.cpp

${OBJECTDIR}/AbstractKMP/Routes.o: AbstractKMP/Routes.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/Routes.o AbstractKMP/Routes.cpp

${OBJECTDIR}/AbstractKMP/StageInfo.o: AbstractKMP/StageInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/AbstractKMP
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/AbstractKMP/StageInfo.o AbstractKMP/StageInfo.cpp

${OBJECTDIR}/CommonTypes.o: CommonTypes.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/CommonTypes.o CommonTypes.cpp

${OBJECTDIR}/KMP.o: KMP.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/KMP.o KMP.cpp

${OBJECTDIR}/Libs/EndianBinaryIO.o: Libs/EndianBinaryIO.cpp 
	${MKDIR} -p ${OBJECTDIR}/Libs
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Libs/EndianBinaryIO.o Libs/EndianBinaryIO.cpp

${OBJECTDIR}/Libs/pugixml.o: Libs/pugixml.cpp 
	${MKDIR} -p ${OBJECTDIR}/Libs
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Libs/pugixml.o Libs/pugixml.cpp

${OBJECTDIR}/Sections/AreaPoint.o: Sections/AreaPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/AreaPoint.o Sections/AreaPoint.cpp

${OBJECTDIR}/Sections/Camera.o: Sections/Camera.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/Camera.o Sections/Camera.cpp

${OBJECTDIR}/Sections/CannonPoint.o: Sections/CannonPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/CannonPoint.o Sections/CannonPoint.cpp

${OBJECTDIR}/Sections/CheckPath.o: Sections/CheckPath.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/CheckPath.o Sections/CheckPath.cpp

${OBJECTDIR}/Sections/CheckPoint.o: Sections/CheckPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/CheckPoint.o Sections/CheckPoint.cpp

${OBJECTDIR}/Sections/CourseSect.o: Sections/CourseSect.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/CourseSect.o Sections/CourseSect.cpp

${OBJECTDIR}/Sections/EnemyPath.o: Sections/EnemyPath.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/EnemyPath.o Sections/EnemyPath.cpp

${OBJECTDIR}/Sections/EnemyPoint.o: Sections/EnemyPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/EnemyPoint.o Sections/EnemyPoint.cpp

${OBJECTDIR}/Sections/GliderPath.o: Sections/GliderPath.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/GliderPath.o Sections/GliderPath.cpp

${OBJECTDIR}/Sections/GliderPoint.o: Sections/GliderPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/GliderPoint.o Sections/GliderPoint.cpp

${OBJECTDIR}/Sections/GlobalObject.o: Sections/GlobalObject.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/GlobalObject.o Sections/GlobalObject.cpp

${OBJECTDIR}/Sections/ItemPath.o: Sections/ItemPath.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/ItemPath.o Sections/ItemPath.cpp

${OBJECTDIR}/Sections/ItemPoint.o: Sections/ItemPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/ItemPoint.o Sections/ItemPoint.cpp

${OBJECTDIR}/Sections/JugemPoint.o: Sections/JugemPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/JugemPoint.o Sections/JugemPoint.cpp

${OBJECTDIR}/Sections/KartPoint.o: Sections/KartPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/KartPoint.o Sections/KartPoint.cpp

${OBJECTDIR}/Sections/MissionPoint.o: Sections/MissionPoint.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/MissionPoint.o Sections/MissionPoint.cpp

${OBJECTDIR}/Sections/PointInfo.o: Sections/PointInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/PointInfo.o Sections/PointInfo.cpp

${OBJECTDIR}/Sections/StageInfo.o: Sections/StageInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sections
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Sections/StageInfo.o Sections/StageInfo.cpp

${OBJECTDIR}/main.o: main.cpp 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/kmpedit.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
