
void FUN_00441560(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
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
        ((*(uint *)(DAT_00fb1318 + 0xc01c) >> 3 & 1) != 0)) &&
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
    if (*(int *)(param_1 + 0xf4) == DAT_00f95be0) {
      fVar1 = *(float *)(param_1 + 0x10c);
      fVar3 = (float)(*(int *)(DAT_00fb1318 + 0xc00c) - *(int *)(param_1 + 0x130)) - fVar1;
      fVar2 = *(float *)(param_1 + 0x110);
      fVar4 = (float)(*(int *)(DAT_00fb1318 + 0xc010) - *(int *)(param_1 + 0x134)) - fVar2;
      if ((((fVar3 < fVar1) && (fVar4 < fVar2)) &&
          ((-fVar1 < fVar3 &&
           ((-fVar2 < fVar4 && (iVar6 = FUN_00443dc0(), *(int *)(iVar6 + 0x20) != 0)))))) &&
         (*(char *)(iVar6 + 0x368) == '\x01')) {
        *(float *)(param_1 + 0x114) = fVar3;
        *(float *)(param_1 + 0x118) = fVar4;
      }
      if (DAT_00fba80c == 0) {
        iVar6 = FUN_00891268(0x57c);
        if (iVar6 == 0) {
          DAT_00fba80c = 0;
        }
        else {
          DAT_00fba80c = FUN_006f1370();
        }
      }
      if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x368) == '\x03')) {
        *(float *)(param_1 + 0x114) = fVar3;
        *(float *)(param_1 + 0x120) = fVar3;
        *(float *)(param_1 + 0x118) = fVar4;
        *(float *)(param_1 + 0x124) = fVar4;
        ClipCursor((RECT *)0x0);
      }
      if (DAT_00fba80c == 0) {
        iVar6 = FUN_00891268(0x57c);
        if (iVar6 == 0) {
          DAT_00fba80c = 0;
        }
        else {
          DAT_00fba80c = FUN_006f1370();
        }
      }
      if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x368) == '\x02')) {
        *(float *)(param_1 + 0x120) = fVar3;
        *(float *)(param_1 + 0x124) = fVar4;
        FUN_006dd590(fVar4);
        FUN_006dd600();
        uVar8 = *(undefined4 *)(param_1 + 0x130);
        *(undefined4 *)(param_1 + 0x114) = *(undefined4 *)(param_1 + 0x120);
        uVar9 = *(undefined4 *)(param_1 + 0x134);
        *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x124);
        uVar10 = *(undefined4 *)(param_1 + 0x138);
        uVar11 = *(undefined4 *)(param_1 + 0x13c);
        uVar7 = FUN_00404aa0(uVar8,uVar9,uVar10,uVar11);
        FUN_007535f0(uVar7,uVar8,uVar9,uVar10,uVar11);
      }
    }
  }
  ExceptionList = local_10;
  return;
}

