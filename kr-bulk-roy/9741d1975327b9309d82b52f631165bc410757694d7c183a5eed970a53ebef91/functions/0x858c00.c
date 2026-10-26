
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00858c00(void)

{
  byte *pbVar1;
  char cVar2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  char *in_ECX;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  byte local_118 [260];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913f1c;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe6578 & 1) == 0) {
    DAT_00fe6578 = DAT_00fe6578 | 1;
    local_8 = 0;
    _DAT_00fe5df8 = 0;
    DAT_00fe5e10 = 0xf;
    _DAT_00fe5e0c = 0;
    DAT_00fe5dfc = 0;
    FUN_00402a70("UNKNOWN",7);
    local_8._0_1_ = 1;
    _DAT_00fe5e18 = 0x14;
    DAT_00fe5e30 = 0xf;
    _DAT_00fe5e2c = 0;
    DAT_00fe5e1c._0_1_ = 0;
    FUN_00402a70("R8G8B8",6);
    local_8._0_1_ = 2;
    _DAT_00fe5e38 = 0x15;
    _DAT_00fe5e50 = 0xf;
    _DAT_00fe5e4c = 0;
    DAT_00fe5e3c = 0;
    FUN_00402a70("A8R8G8B8",8);
    local_8._0_1_ = 3;
    _DAT_00fe5e58 = 0x16;
    _DAT_00fe5e70 = 0xf;
    _DAT_00fe5e6c = 0;
    DAT_00fe5e5c = 0;
    FUN_00402a70("X8R8G8B8",8);
    local_8._0_1_ = 4;
    _DAT_00fe5e78 = 0x17;
    _DAT_00fe5e90 = 0xf;
    _DAT_00fe5e8c = 0;
    DAT_00fe5e7c = 0;
    FUN_00402a70("R5G6B5",6);
    local_8._0_1_ = 5;
    _DAT_00fe5e98 = 0x18;
    _DAT_00fe5eb0 = 0xf;
    _DAT_00fe5eac = 0;
    DAT_00fe5e9c = 0;
    FUN_00402a70("X1R5G5B5",8);
    local_8._0_1_ = 6;
    _DAT_00fe5eb8 = 0x19;
    _DAT_00fe5ed0 = 0xf;
    _DAT_00fe5ecc = 0;
    DAT_00fe5ebc = 0;
    FUN_00402a70("A1R5G5B5",8);
    local_8._0_1_ = 7;
    _DAT_00fe5ed8 = 0x1a;
    _DAT_00fe5ef0 = 0xf;
    _DAT_00fe5eec = 0;
    DAT_00fe5edc = 0;
    FUN_00402a70("A4R4G4B4",8);
    local_8._0_1_ = 8;
    _DAT_00fe5ef8 = 0x1b;
    _DAT_00fe5f10 = 0xf;
    _DAT_00fe5f0c = 0;
    DAT_00fe5efc = 0;
    FUN_00402a70("R3G3B2",6);
    local_8._0_1_ = 9;
    _DAT_00fe5f18 = 0x1c;
    _DAT_00fe5f30 = 0xf;
    _DAT_00fe5f2c = 0;
    DAT_00fe5f1c = 0;
    FUN_00402a70(&DAT_00c545a0,2);
    local_8._0_1_ = 10;
    _DAT_00fe5f38 = 0x1d;
    _DAT_00fe5f50 = 0xf;
    _DAT_00fe5f4c = 0;
    DAT_00fe5f3c = 0;
    FUN_00402a70("A8R3G3B2",8);
    local_8._0_1_ = 0xb;
    _DAT_00fe5f58 = 0x1e;
    _DAT_00fe5f70 = 0xf;
    _DAT_00fe5f6c = 0;
    DAT_00fe5f5c = 0;
    FUN_00402a70("X4R4G4B4",8);
    local_8._0_1_ = 0xc;
    _DAT_00fe5f78 = 0x1f;
    _DAT_00fe5f90 = 0xf;
    _DAT_00fe5f8c = 0;
    DAT_00fe5f7c = 0;
    FUN_00402a70("A2B10G10R10",0xb);
    local_8._0_1_ = 0xd;
    _DAT_00fe5f98 = 0x20;
    _DAT_00fe5fb0 = 0xf;
    _DAT_00fe5fac = 0;
    DAT_00fe5f9c = 0;
    FUN_00402a70("A8B8G8R8",8);
    local_8._0_1_ = 0xe;
    _DAT_00fe5fb8 = 0x21;
    _DAT_00fe5fd0 = 0xf;
    _DAT_00fe5fcc = 0;
    DAT_00fe5fbc = 0;
    FUN_00402a70("X8B8G8R8",8);
    local_8._0_1_ = 0xf;
    _DAT_00fe5fd8 = 0x22;
    _DAT_00fe5ff0 = 0xf;
    _DAT_00fe5fec = 0;
    DAT_00fe5fdc = 0;
    FUN_00402a70("G16R16",6);
    local_8._0_1_ = 0x10;
    _DAT_00fe5ff8 = 0x23;
    _DAT_00fe6010 = 0xf;
    _DAT_00fe600c = 0;
    DAT_00fe5ffc = 0;
    FUN_00402a70("A2R10G10B10",0xb);
    local_8._0_1_ = 0x11;
    _DAT_00fe6018 = 0x24;
    _DAT_00fe6030 = 0xf;
    _DAT_00fe602c = 0;
    DAT_00fe601c = 0;
    FUN_00402a70("A16B16G16R16",0xc);
    local_8._0_1_ = 0x12;
    _DAT_00fe6038 = 0x28;
    _DAT_00fe6050 = 0xf;
    _DAT_00fe604c = 0;
    DAT_00fe603c = 0;
    FUN_00402a70(&DAT_00c54538,4);
    local_8._0_1_ = 0x13;
    _DAT_00fe6058 = 0x29;
    _DAT_00fe6070 = 0xf;
    _DAT_00fe606c = 0;
    DAT_00fe605c = 0;
    FUN_00402a70(&DAT_00c54534,2);
    local_8._0_1_ = 0x14;
    _DAT_00fe6078 = 0x32;
    _DAT_00fe6090 = 0xf;
    _DAT_00fe608c = 0;
    DAT_00fe607c = 0;
    FUN_00402a70(&DAT_00c54530,2);
    local_8._0_1_ = 0x15;
    _DAT_00fe6098 = 0x33;
    _DAT_00fe60b0 = 0xf;
    _DAT_00fe60ac = 0;
    DAT_00fe609c = 0;
    FUN_00402a70(&DAT_00c54528,4);
    local_8._0_1_ = 0x16;
    _DAT_00fe60b8 = 0x34;
    _DAT_00fe60d0 = 0xf;
    _DAT_00fe60cc = 0;
    DAT_00fe60bc = 0;
    FUN_00402a70(&DAT_00c54520,4);
    local_8._0_1_ = 0x17;
    _DAT_00fe60d8 = 0x3c;
    _DAT_00fe60f0 = 0xf;
    _DAT_00fe60ec = 0;
    DAT_00fe60dc = 0;
    FUN_00402a70(&DAT_00c54518,4);
    local_8._0_1_ = 0x18;
    _DAT_00fe60f8 = 0x3d;
    _DAT_00fe6110 = 0xf;
    _DAT_00fe610c = 0;
    DAT_00fe60fc = 0;
    FUN_00402a70("L6V5U5",6);
    local_8._0_1_ = 0x19;
    _DAT_00fe6118 = 0x3e;
    _DAT_00fe6130 = 0xf;
    _DAT_00fe612c = 0;
    DAT_00fe611c = 0;
    FUN_00402a70("X8L8V8U8",8);
    local_8._0_1_ = 0x1a;
    _DAT_00fe6138 = 0x3f;
    _DAT_00fe6150 = 0xf;
    _DAT_00fe614c = 0;
    DAT_00fe613c = 0;
    FUN_00402a70("Q8W8V8U8",8);
    local_8._0_1_ = 0x1b;
    _DAT_00fe6158 = 0x40;
    _DAT_00fe6170 = 0xf;
    _DAT_00fe616c = 0;
    DAT_00fe615c = 0;
    FUN_00402a70("V16U16",6);
    local_8._0_1_ = 0x1c;
    _DAT_00fe6178 = 0x43;
    _DAT_00fe6190 = 0xf;
    _DAT_00fe618c = 0;
    DAT_00fe617c = 0;
    FUN_00402a70("A2W10V10U10",0xb);
    local_8._0_1_ = 0x1d;
    _DAT_00fe6198 = 0x59565955;
    _DAT_00fe61b0 = 0xf;
    _DAT_00fe61ac = 0;
    DAT_00fe619c = 0;
    FUN_00402a70(&DAT_00c544dc,4);
    local_8._0_1_ = 0x1e;
    _DAT_00fe61b8 = 0x47424752;
    _DAT_00fe61d0 = 0xf;
    _DAT_00fe61cc = 0;
    DAT_00fe61bc = 0;
    FUN_00402a70("R8G8_B8G8",9);
    local_8._0_1_ = 0x1f;
    _DAT_00fe61d8 = 0x32595559;
    _DAT_00fe61f0 = 0xf;
    _DAT_00fe61ec = 0;
    DAT_00fe61dc = 0;
    FUN_00402a70(&DAT_00c544c8,4);
    local_8._0_1_ = 0x20;
    _DAT_00fe61f8 = 0x42475247;
    _DAT_00fe6210 = 0xf;
    _DAT_00fe620c = 0;
    DAT_00fe61fc = 0;
    FUN_00402a70("G8R8_G8B8",9);
    local_8._0_1_ = 0x21;
    _DAT_00fe6218 = 0x31545844;
    _DAT_00fe6230 = 0xf;
    _DAT_00fe622c = 0;
    DAT_00fe621c = 0;
    FUN_00402a70(&DAT_00c544b4,4);
    local_8._0_1_ = 0x22;
    _DAT_00fe6238 = 0x32545844;
    _DAT_00fe6250 = 0xf;
    _DAT_00fe624c = 0;
    DAT_00fe623c = 0;
    FUN_00402a70(&DAT_00c544ac,4);
    local_8._0_1_ = 0x23;
    _DAT_00fe6258 = 0x33545844;
    _DAT_00fe6270 = 0xf;
    _DAT_00fe626c = 0;
    DAT_00fe625c = 0;
    FUN_00402a70(&DAT_00c544a4,4);
    local_8._0_1_ = 0x24;
    _DAT_00fe6278 = 0x34545844;
    _DAT_00fe6290 = 0xf;
    _DAT_00fe628c = 0;
    DAT_00fe627c = 0;
    FUN_00402a70(&DAT_00c5449c,4);
    local_8._0_1_ = 0x25;
    _DAT_00fe6298 = 0x35545844;
    _DAT_00fe62b0 = 0xf;
    _DAT_00fe62ac = 0;
    DAT_00fe629c = 0;
    FUN_00402a70(&DAT_00c54494,4);
    local_8._0_1_ = 0x26;
    _DAT_00fe62b8 = 0x46;
    _DAT_00fe62d0 = 0xf;
    _DAT_00fe62cc = 0;
    DAT_00fe62bc = 0;
    FUN_00402a70("D16_LOCKABLE",0xc);
    local_8._0_1_ = 0x27;
    _DAT_00fe62d8 = 0x47;
    _DAT_00fe62f0 = 0xf;
    _DAT_00fe62ec = 0;
    DAT_00fe62dc = 0;
    FUN_00402a70(&DAT_00c54480,3);
    local_8._0_1_ = 0x28;
    _DAT_00fe62f8 = 0x49;
    _DAT_00fe6310 = 0xf;
    _DAT_00fe630c = 0;
    DAT_00fe62fc = 0;
    FUN_00402a70("D15S1",5);
    local_8._0_1_ = 0x29;
    _DAT_00fe6318 = 0x4b;
    _DAT_00fe6330 = 0xf;
    _DAT_00fe632c = 0;
    DAT_00fe631c = 0;
    FUN_00402a70("D24S8",5);
    local_8._0_1_ = 0x2a;
    _DAT_00fe6338 = 0x4d;
    _DAT_00fe6350 = 0xf;
    _DAT_00fe634c = 0;
    DAT_00fe633c = 0;
    FUN_00402a70("D24X8",5);
    local_8._0_1_ = 0x2b;
    _DAT_00fe6358 = 0x4f;
    _DAT_00fe6370 = 0xf;
    _DAT_00fe636c = 0;
    DAT_00fe635c = 0;
    FUN_00402a70("D24X4S4",7);
    local_8._0_1_ = 0x2c;
    _DAT_00fe6378 = 0x50;
    _DAT_00fe6390 = 0xf;
    _DAT_00fe638c = 0;
    DAT_00fe637c = 0;
    FUN_00402a70(&DAT_00c5445c,3);
    local_8._0_1_ = 0x2d;
    _DAT_00fe6398 = 0x52;
    _DAT_00fe63b0 = 0xf;
    _DAT_00fe63ac = 0;
    DAT_00fe639c = 0;
    FUN_00402a70("D32F_LOCKABLE",0xd);
    local_8._0_1_ = 0x2e;
    _DAT_00fe63b8 = 0x53;
    _DAT_00fe63d0 = 0xf;
    _DAT_00fe63cc = 0;
    DAT_00fe63bc = 0;
    FUN_00402a70("D24FS8",6);
    local_8._0_1_ = 0x2f;
    _DAT_00fe63d8 = 0x51;
    _DAT_00fe63f0 = 0xf;
    _DAT_00fe63ec = 0;
    DAT_00fe63dc = 0;
    FUN_00402a70(&DAT_00c54440,3);
    local_8._0_1_ = 0x30;
    _DAT_00fe63f8 = 100;
    _DAT_00fe6410 = 0xf;
    _DAT_00fe640c = 0;
    DAT_00fe63fc = 0;
    FUN_00402a70("VERTEXDATA",10);
    local_8._0_1_ = 0x31;
    _DAT_00fe6418 = 0x65;
    _DAT_00fe6430 = 0xf;
    _DAT_00fe642c = 0;
    DAT_00fe641c = 0;
    FUN_00402a70("INDEX16",7);
    local_8._0_1_ = 0x32;
    _DAT_00fe6438 = 0x66;
    _DAT_00fe6450 = 0xf;
    _DAT_00fe644c = 0;
    DAT_00fe643c = 0;
    FUN_00402a70("INDEX32",7);
    local_8._0_1_ = 0x33;
    _DAT_00fe6458 = 0x6e;
    _DAT_00fe6470 = 0xf;
    _DAT_00fe646c = 0;
    DAT_00fe645c = 0;
    FUN_00402a70("Q16W16V16U16",0xc);
    local_8._0_1_ = 0x34;
    _DAT_00fe6478 = 0x3154454d;
    _DAT_00fe6490 = 0xf;
    _DAT_00fe648c = 0;
    DAT_00fe647c = 0;
    FUN_00402a70("MULTI2_ARGB8",0xc);
    local_8._0_1_ = 0x35;
    _DAT_00fe6498 = 0x6f;
    _DAT_00fe64b0 = 0xf;
    _DAT_00fe64ac = 0;
    DAT_00fe649c = 0;
    FUN_00402a70(&DAT_00c543fc,4);
    local_8._0_1_ = 0x36;
    _DAT_00fe64b8 = 0x70;
    _DAT_00fe64d0 = 0xf;
    _DAT_00fe64cc = 0;
    DAT_00fe64bc = 0;
    FUN_00402a70("G16R16F",7);
    local_8._0_1_ = 0x37;
    _DAT_00fe64d8 = 0x71;
    _DAT_00fe64f0 = 0xf;
    _DAT_00fe64ec = 0;
    DAT_00fe64dc = 0;
    FUN_00402a70("A16B16G16R16F",0xd);
    local_8._0_1_ = 0x38;
    _DAT_00fe64f8 = 0x72;
    _DAT_00fe6510 = 0xf;
    _DAT_00fe650c = 0;
    DAT_00fe64fc = 0;
    FUN_00402a70(&DAT_00c543dc,4);
    local_8._0_1_ = 0x39;
    _DAT_00fe6518 = 0x73;
    _DAT_00fe6530 = 0xf;
    _DAT_00fe652c = 0;
    DAT_00fe651c = 0;
    FUN_00402a70("G32R32F",7);
    local_8._0_1_ = 0x3a;
    _DAT_00fe6538 = 0x74;
    _DAT_00fe6550 = 0xf;
    _DAT_00fe654c = 0;
    DAT_00fe653c = 0;
    FUN_00402a70("A32B32G32R32F",0xd);
    local_8 = CONCAT31(local_8._1_3_,0x3b);
    _DAT_00fe6558 = 0x75;
    _DAT_00fe6570 = 0xf;
    _DAT_00fe656c = 0;
    DAT_00fe655c = 0;
    FUN_00402a70("CxV8U8",6);
    _atexit((_func_4879 *)&LAB_00bd0f00);
  }
  iVar5 = -(int)in_ECX;
  do {
    cVar2 = *in_ECX;
    in_ECX[(int)(local_118 + iVar5)] = cVar2;
    in_ECX = in_ECX + 1;
  } while (cVar2 != '\0');
  __strupr((char *)local_118);
  pbVar7 = &DAT_00fe5dfc;
  do {
    pbVar6 = pbVar7;
    if (0xf < *(uint *)(pbVar7 + 0x14)) {
      pbVar6 = *(byte **)pbVar7;
    }
    pbVar4 = local_118;
    do {
      bVar3 = *pbVar4;
      bVar8 = bVar3 < *pbVar6;
      if (bVar3 != *pbVar6) {
LAB_00859836:
        iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_0085983b;
      }
      if (bVar3 == 0) break;
      bVar3 = pbVar4[1];
      bVar8 = bVar3 < pbVar6[1];
      if (bVar3 != pbVar6[1]) goto LAB_00859836;
      pbVar4 = pbVar4 + 2;
      pbVar6 = pbVar6 + 2;
    } while (bVar3 != 0);
    iVar5 = 0;
LAB_0085983b:
    if (iVar5 == 0) {
      pbVar6 = local_118;
      do {
        bVar3 = *pbVar6;
        pbVar6 = pbVar6 + 1;
      } while (bVar3 != 0);
      pbVar4 = pbVar7;
      if (0xf < *(uint *)(pbVar7 + 0x14)) {
        pbVar4 = *(byte **)pbVar7;
      }
      pbVar1 = pbVar4 + 1;
      do {
        bVar3 = *pbVar4;
        pbVar4 = pbVar4 + 1;
      } while (bVar3 != 0);
      if ((int)pbVar6 - (int)(local_118 + 1) == (int)pbVar4 - (int)pbVar1) break;
    }
    pbVar7 = pbVar7 + 0x20;
  } while ((int)pbVar7 < 0xfe657c);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

