
void FUN_0053db30(int *param_1,undefined2 param_2)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  undefined4 *puVar8;
  short in_DX;
  undefined4 *local_1c;
  undefined4 *local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a26c;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = *param_1;
  if (iVar5 != param_1[1]) {
    do {
      if ((uint)*(ushort *)(iVar5 + 2) == (int)in_DX) {
        *(undefined2 *)(iVar5 + 8) = param_2;
      }
      iVar5 = iVar5 + 0x14;
    } while (iVar5 != param_1[1]);
  }
  iVar5 = param_1[4];
  if (iVar5 != param_1[5]) {
    local_14 = (uint)in_DX;
    do {
      if ((*(ushort *)(iVar5 + 2) == local_14) &&
         (*(undefined2 *)(iVar5 + 8) = param_2, *(short *)(iVar5 + 4) == 3)) {
        uVar2 = *(ushort *)(iVar5 + 0xc);
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_8 = 0;
          FUN_0051c120(uVar4);
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_8 = 0xffffffff;
        }
        cVar1 = *(char *)((int)DAT_00f8d91c[1] + 0x15);
        puVar6 = (undefined4 *)DAT_00f8d91c[1];
        local_18 = DAT_00f8d91c;
        while (puVar8 = puVar6, cVar1 == '\0') {
          if ((int)puVar8[3] < (int)(uint)uVar2) {
            puVar6 = (undefined4 *)puVar8[2];
            puVar8 = local_18;
          }
          else {
            puVar6 = (undefined4 *)*puVar8;
          }
          cVar1 = *(char *)((int)puVar6 + 0x15);
          local_18 = puVar8;
        }
        if ((local_18 == DAT_00f8d91c) || ((int)(uint)uVar2 < (int)local_18[3])) {
          local_1c = DAT_00f8d91c;
          ppuVar7 = &local_1c;
        }
        else {
          ppuVar7 = &local_18;
        }
        if ((*ppuVar7 != DAT_00f8d91c) && (iVar3 = (*ppuVar7)[4], iVar3 != 0)) {
          if ((DAT_00fc1ac0 & 1) == 0) {
            DAT_00fc1ac0 = DAT_00fc1ac0 | 1;
            local_8 = 1;
            FUN_00558100();
            _atexit((_func_4879 *)&LAB_00bcdea0);
            local_8 = 0xffffffff;
          }
          FUN_00558200(*(undefined4 *)(iVar3 + 0x20));
        }
      }
      iVar5 = iVar5 + 0x18;
    } while (iVar5 != param_1[5]);
  }
  ExceptionList = local_10;
  return;
}

