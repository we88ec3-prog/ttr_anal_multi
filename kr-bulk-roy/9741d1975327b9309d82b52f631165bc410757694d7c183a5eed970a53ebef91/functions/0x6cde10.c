
void FUN_006cde10(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int *piVar6;
  uint uVar7;
  char ****_Filename;
  FILE *_File;
  int in_ECX;
  int *piVar8;
  undefined1 local_3e4 [152];
  undefined1 local_34c [152];
  undefined1 local_2b4 [152];
  undefined1 local_21c [152];
  undefined **local_184 [6];
  undefined4 *local_16c;
  char ***local_164 [5];
  uint local_150;
  uint local_138;
  undefined4 local_128;
  uint local_124;
  char local_110;
  undefined1 local_10c [156];
  uint local_70 [4];
  undefined4 local_60;
  uint local_5c;
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00919c02;
  local_10 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar7;
  FUN_0072ee30(local_184);
  local_8 = 0;
  FUN_0072fc40(local_3e4,"utf-8");
  local_8._0_1_ = 1;
  FUN_0072e1e0(uVar7);
  FUN_0072e420(local_34c,"JoypadMapping");
  local_8._0_1_ = 2;
  FUN_0072e420(local_2b4,"DeviceType");
  local_8._0_1_ = 3;
  FUN_0072e770(local_2b4,&DAT_00bed1d4);
  local_5c = 0xf;
  local_60 = 0;
  local_70[0] = local_70[0] & 0xffffff00;
  FUN_00402a70("sourceDeviceType",0x10);
  local_8._0_1_ = 4;
  FUN_0072e890(local_70,in_ECX + 0xb0);
  local_8._0_1_ = 3;
  if (0xf < local_5c) {
    FUN_0089120c(local_70[0]);
  }
  FUN_0072e420(local_10c,"DefaultAxisThreshold");
  local_8._0_1_ = 5;
  FUN_00730d80(local_54,&DAT_00c0d6dc,*(undefined4 *)(in_ECX + 0xcc));
  FUN_0072e770(local_10c,"value");
  FUN_0072e1e0();
  local_8._0_1_ = 3;
  FUN_0072e520();
  FUN_0072e420(local_10c,"AxisPow");
  local_8._0_1_ = 6;
  FUN_00730d80(local_54,&DAT_00c0d6dc,*(undefined4 *)(in_ECX + 0xd0));
  FUN_0072e770(local_10c,"value");
  FUN_0072e1e0();
  local_8._0_1_ = 3;
  FUN_0072e520();
  FUN_0072e420(local_10c,"Mappings");
  local_8._0_1_ = 7;
  uVar5 = (undefined1)local_8;
  local_8._0_1_ = 7;
  piVar8 = (int *)**(int **)(in_ECX + 0xd8);
  if (piVar8 != *(int **)(in_ECX + 0xd8)) {
    do {
      FUN_0072e420(local_21c,"Control");
      local_8._0_1_ = 8;
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[4]);
      FUN_0072e770(local_21c,&DAT_00bed1d0);
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[5]);
      FUN_0072e770(local_21c,"mapping");
      FUN_0072e1e0();
      local_8._0_1_ = 7;
      FUN_0072e520();
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar2 = (int *)piVar8[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar8 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar6 = (int *)piVar8[1];
          piVar2 = piVar8;
          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar6 = (int *)piVar8[1];
            piVar2 = piVar8;
          }
        }
      }
      uVar5 = (undefined1)local_8;
    } while (piVar8 != *(int **)(in_ECX + 0xd8));
  }
  local_8._0_1_ = uVar5;
  FUN_0072e1e0();
  local_8._0_1_ = 3;
  FUN_0072e520();
  FUN_0072e420(local_21c,"UIModeMappings");
  local_8._0_1_ = 9;
  uVar5 = (undefined1)local_8;
  local_8._0_1_ = 9;
  piVar8 = (int *)**(int **)(in_ECX + 0xe8);
  if (piVar8 != *(int **)(in_ECX + 0xe8)) {
    do {
      FUN_0072e420(local_10c,"Forward");
      local_8._0_1_ = 10;
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[4]);
      FUN_0072e770(local_10c,&DAT_00bed1d0);
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[5]);
      FUN_0072e770(local_10c,"forwarding");
      FUN_0072e1e0();
      local_8._0_1_ = 9;
      FUN_0072e520();
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar2 = (int *)piVar8[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar8 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar6 = (int *)piVar8[1];
          piVar2 = piVar8;
          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar6 = (int *)piVar8[1];
            piVar2 = piVar8;
          }
        }
      }
      uVar5 = (undefined1)local_8;
    } while (piVar8 != *(int **)(in_ECX + 0xe8));
  }
  local_8._0_1_ = uVar5;
  piVar8 = (int *)**(int **)(in_ECX + 0xf8);
  if (piVar8 != *(int **)(in_ECX + 0xf8)) {
    do {
      FUN_0072e420(local_10c,"MouseButtonSim");
      local_8._0_1_ = 0xb;
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[4]);
      FUN_0072e770(local_10c,&DAT_00bed1d0);
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[5]);
      FUN_0072e770(local_10c,"button");
      FUN_0072e1e0();
      local_8._0_1_ = 9;
      FUN_0072e520();
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar2 = (int *)piVar8[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar8 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar6 = (int *)piVar8[1];
          piVar2 = piVar8;
          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar6 = (int *)piVar8[1];
            piVar2 = piVar8;
          }
        }
      }
    } while (piVar8 != *(int **)(in_ECX + 0xf8));
  }
  piVar8 = (int *)**(int **)(in_ECX + 0x108);
  if (piVar8 != *(int **)(in_ECX + 0x108)) {
    do {
      FUN_0072e420(local_10c,"UIKeyMapping");
      local_8._0_1_ = 0xc;
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[4]);
      FUN_0072e770(local_10c,&DAT_00bed1d0);
      FUN_00730d80(local_54,&DAT_00c0d6dc,piVar8[5]);
      FUN_0072e770(local_10c,"mapping");
      FUN_0072e1e0();
      local_8._0_1_ = 9;
      FUN_0072e520();
      if (*(char *)((int)piVar8 + 0x19) == '\0') {
        piVar2 = (int *)piVar8[2];
        if (*(char *)((int)piVar2 + 0x19) == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar8 = piVar2;
          piVar2 = (int *)*piVar2;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar2 + 0x19);
            piVar8 = piVar2;
            piVar2 = (int *)*piVar2;
          }
        }
        else {
          cVar1 = *(char *)(piVar8[1] + 0x19);
          piVar6 = (int *)piVar8[1];
          piVar2 = piVar8;
          while ((piVar8 = piVar6, cVar1 == '\0' && (piVar2 == (int *)piVar8[2]))) {
            cVar1 = *(char *)(piVar8[1] + 0x19);
            piVar6 = (int *)piVar8[1];
            piVar2 = piVar8;
          }
        }
      }
    } while (piVar8 != *(int **)(in_ECX + 0x108));
  }
  FUN_0072e1e0();
  local_8._0_1_ = 3;
  FUN_0072e520();
  FUN_0072e1e0();
  local_8._0_1_ = 2;
  FUN_0072e520();
  FUN_0072e1e0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0072e520();
  _Filename = (char ****)local_164[0];
  if (local_150 < 0x10) {
    _Filename = local_164;
  }
  _File = _fopen((char *)_Filename,"w");
  if (_File != (FILE *)0x0) {
    if (local_110 != '\0') {
      FID_conflict__fputc(0xef,_File);
      FID_conflict__fputc(0xbb,_File);
      FID_conflict__fputc(0xbf,_File);
    }
    (*(code *)local_184[0][1])(_File,0);
    _ferror(_File);
    _fclose(_File);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_005902f0();
  local_184[0] = TiXmlDocument::vftable;
  if (0xf < local_124) {
    FUN_0089120c(local_138);
  }
  local_124 = 0xf;
  local_128 = 0;
  local_138 = local_138 & 0xffffff00;
  local_184[0] = TiXmlNode::vftable;
  local_8 = 0xe;
  puVar4 = local_16c;
  while (puVar4 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)*puVar4;
    puVar4 = (undefined4 *)puVar4[0x10];
    (*(code *)*puVar3)(1);
  }
  if (0xf < local_150) {
    FUN_0089120c(local_164[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

