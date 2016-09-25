/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   KMP.cpp
 * Author: Ermii
 * 
 * Created on 20 settembre 2016, 21.50
 */

#include "KMP.h"
#include "Sections/EnemyPath.h"

//KMP Header

KMPHeader::KMPHeader(EndianBinaryReader& er)
{
    signature = er.ReadString(4);
    filesize = er.ReadUInt32();
    nr_sections = er.ReadUInt16();
    header_size = er.ReadUInt16();
    version = er.ReadUInt32();
    for (int i=0;i<nr_sections;i++)
    {
        section_offsets[i] = er.ReadUInt32();
    }
}

KMPHeader::KMPHeader()
{
    //Default KMP Parameters
    signature = "DMDC";
    filesize = 0;
    nr_sections = 0x12;
    header_size = 0x58;
    version = 0x0C1C;
    //section_offsets = new uint32_t[nr_sections];
    for (int i=0;i<nr_sections;i++)
    {
        section_offsets[i] = -1;
    }
}

void KMPHeader::Write(EndianBinaryWriter& ew)
{
    ew.Write(signature);
    ew.Write(filesize);
    ew.Write(nr_sections);
    ew.Write(header_size);
    ew.Write(version);
    //section_offsets = new uint32_t[nr_sections];
    for (int i=0;i<nr_sections;i++)
    {
        ew.Write(section_offsets[i]);
    }
}

void KMPHeader::WriteFileSize(EndianBinaryWriter& ew)
{
    filesize = (uint32_t)ew.Position();
    ew.Seek(4,POS_SET);
    ew.Write(filesize);
}

void KMPHeader::WriteSectionInfo(EndianBinaryWriter& ew, uint32_t index)
{
    uint64_t cur_pos = ew.Position();
    section_offsets[index] = (uint32_t)cur_pos - header_size;
    ew.Seek(16+index*sizeof(uint32_t),POS_SET);
    ew.Write(section_offsets[index]);
    ew.Seek(cur_pos,POS_SET);
}

//KMP

KMP::KMP(FILE* file_p) 
{
    EndianBinaryReader er(file_p);
    header = new KMPHeader(er);
    for (int i=0;i<header->nr_sections;i++)
    {
        er.Seek(header->header_size+header->section_offsets[i],POS_SET);
        string temp_signature = er.ReadString(4);
        er.Seek(header->header_size+header->section_offsets[i],POS_SET);
        if (temp_signature=="TPTK"){ ktpt = new KartPoint(er); }
        if (temp_signature=="TPNE"){ enpt = new EnemyPoint(er); }
        if (temp_signature=="HPNE"){ enph = new EnemyPath(er); }
        if (temp_signature=="TPTI"){ itpt = new ItemPoint(er); }
        if (temp_signature=="HPTI"){ itph = new ItemPath(er); }
        if (temp_signature=="TPKC"){ ckpt = new CheckPoint(er); }
        if (temp_signature=="HPKC"){ ckph = new CheckPath(er); }
        if (temp_signature=="JBOG"){ gobj = new GlobalObject(er); }
        if (temp_signature=="ITOP"){ poti = new PointInfo(er); }
        if (temp_signature=="AERA"){ area = new AreaPoint(er); }
        if (temp_signature=="EMAC"){ came = new Camera(er); }
        if (temp_signature=="TPGJ"){ jgpt = new JugemPoint(er); }
        if (temp_signature=="TPNC"){ cnpt = new CannonPoint(er); }
        if (temp_signature=="TPSM"){ mspt = new MissionPoint(er); }
        if (temp_signature=="IGTS"){ stgi = new StageInfo(er); }
        if (temp_signature=="SROC"){ cors = new CourseSect(er); }
        if (temp_signature=="TPLG"){ glpt = new GliderPoint(er); }
        if (temp_signature=="HPLG"){ glph = new GliderPath(er); }
    }
    er.Close();
}

void KMP::Write(FILE* file_p)
{
    EndianBinaryWriter ew(file_p);
    header->Write(ew);
    uint64_t position = ew.Position();
    uint32_t section_index = 0;
    header->WriteSectionInfo(ew,section_index);
    ktpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    enpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    enph->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    itpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    itph->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    ckpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    ckph->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    gobj->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    poti->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    area->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    came->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    jgpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    cnpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    mspt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    stgi->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    cors->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    glpt->Write(ew);
    section_index++;
    header->WriteSectionInfo(ew,section_index);
    glph->Write(ew);
    header->WriteFileSize(ew);
    ew.Close();
}