
void FUN_00475c10(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00917aac;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(param_1 + 0xe9) == '\0') {
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990(uVar5);
      _atexit((_func_4879 *)&LAB_00bccc70);
    }
    local_8 = 0xffffffff;
    if (((*(int *)(param_1 + 0xf4) == DAT_00f95bdc) &&
        ((*(uint *)(DAT_00fb1318 + 0xc01c) >> 3 & 1) == 0)) &&
       ((*(byte *)(DAT_00fb1318 + 0xc01c) & 1) != 0)) {
      FUN_00443dc0();
      iVar6 = FUN_006f1bc0();
      if (*(int *)(iVar6 + 8) != 0) {
        FUN_00443dc0();
        iVar6 = FUN_006f1bc0();
        *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) =
             *(float *)(*(int *)(DAT_00fb1318 + 0xbfe8) + 0x24) + (float)*(int *)(iVar6 + 8) * -0.1;
        FUN_006dd6f0();
      }
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 1;
      FUN_0074d990(uVar5);
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    iVar6 = DAT_00fba80c;
    if (*(int *)(param_1 + 0xf4) == DAT_00f95be0) {
      fVar1 = *(float *)(param_1 + 0x120);
      fVar3 = (float)(*(int *)(DAT_00fb1318 + 0xc00c) - *(int *)(param_1 + 0x144)) - fVar1;
      fVar2 = *(float *)(param_1 + 0x124);
      fVar4 = (float)(*(int *)(DAT_00fb1318 + 0xc010) - *(int *)(param_1 + 0x148)) - fVar2;
      if (((fVar1 <= fVar3) || (fVar2 <= fVar4)) ||
         ((fVar3 <= -fVar1 || ((fVar4 <= -fVar2 || (*(char *)(param_1 + 0x140) == '\0')))))) {
        *(float *)(param_1 + 0x128) = fVar3;
        *(float *)(param_1 + 0x134) = fVar3;
        *(float *)(param_1 + 300) = fVar4;
        *(float *)(param_1 + 0x138) = fVar4;
        if (iVar6 == 0) {
          iVar6 = FUN_00891268(0x57c);
          if (iVar6 == 0) {
            iVar6 = 0;
            DAT_00fba80c = iVar6;
          }
          else {
            iVar6 = FUN_006f1370();
            DAT_00fba80c = iVar6;
          }
        }
        if (((*(int *)(iVar6 + 0x20) != 0) && (*(char *)(iVar6 + 0x369) == '\x01')) ||
           ((iVar8 = FUN_00443dc0(), iVar6 = DAT_00fba80c, *(int *)(iVar8 + 0x20) != 0 &&
            (*(char *)(iVar8 + 0x368) == '\x01')))) {
          *(undefined1 *)(param_1 + 0x140) = 0;
        }
        if (iVar6 == 0) {
          iVar6 = FUN_00891268(0x57c);
          if (iVar6 == 0) {
            iVar6 = 0;
            DAT_00fba80c = iVar6;
          }
          else {
            iVar6 = FUN_006f1370();
            DAT_00fba80c = iVar6;
          }
        }
        if (((*(int *)(iVar6 + 0x20) != 0) && (*(char *)(iVar6 + 0x369) == '\x03')) ||
           ((iVar6 = FUN_00443dc0(), *(int *)(iVar6 + 0x20) != 0 &&
            (*(char *)(iVar6 + 0x368) == '\x03')))) {
          *(undefined1 *)(param_1 + 0x140) = 1;
          ClipCursor((RECT *)0x0);
        }
      }
      else {
        iVar6 = FUN_00443dc0();
        if (((*(int *)(iVar6 + 0x20) == 0) || (*(char *)(iVar6 + 0x368) != '\x01')) &&
           ((iVar6 = FUN_00443dc0(), *(int *)(iVar6 + 0x20) == 0 ||
            (*(char *)(iVar6 + 0x369) != '\x01')))) {
          iVar6 = FUN_00443dc0();
          if (((*(int *)(iVar6 + 0x20) != 0) && (*(char *)(iVar6 + 0x368) == '\x03')) ||
             ((iVar6 = FUN_00443dc0(), *(int *)(iVar6 + 0x20) != 0 &&
              (*(char *)(iVar6 + 0x369) == '\x03')))) {
            ClipCursor((RECT *)0x0);
          }
        }
        else {
          *(float *)(param_1 + 0x128) = fVar3;
          *(float *)(param_1 + 300) = fVar4;
        }
        iVar6 = FUN_00443dc0();
        if ((*(int *)(iVar6 + 0x20) != 0) && (*(char *)(iVar6 + 0x368) == '\x02')) {
          *(float *)(param_1 + 0x134) = fVar3;
          *(float *)(param_1 + 0x138) = fVar4;
          FUN_006dd590(fVar4);
          FUN_006dd600();
          uVar9 = *(undefined4 *)(param_1 + 0x144);
          *(undefined4 *)(param_1 + 0x128) = *(undefined4 *)(param_1 + 0x134);
          uVar10 = *(undefined4 *)(param_1 + 0x148);
          *(undefined4 *)(param_1 + 300) = *(undefined4 *)(param_1 + 0x138);
          uVar11 = *(undefined4 *)(param_1 + 0x14c);
          uVar12 = *(undefined4 *)(param_1 + 0x150);
          uVar7 = FUN_00404aa0(uVar9,uVar10,uVar11,uVar12);
          FUN_007535f0(uVar7,uVar9,uVar10,uVar11,uVar12);
          ExceptionList = local_10;
          return;
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}

