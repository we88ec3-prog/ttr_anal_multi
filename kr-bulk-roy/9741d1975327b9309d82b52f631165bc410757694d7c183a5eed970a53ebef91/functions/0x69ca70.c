
void FUN_0069ca70(void)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int in_ECX;
  int iVar8;
  int *piVar9;
  uint uVar10;
  uint local_3c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c7bc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar5 = DAT_00f94300;
  local_c = 0xffffffff;
  uVar2 = *(uint *)(DAT_00f94300 + 0x50d0);
  uVar10 = (uint)(uVar2 % 0xf != 0) + uVar2 / 0xf;
  *(uint *)(in_ECX + 0x148) = uVar10;
  if (uVar2 == 0) {
    *(undefined4 *)(in_ECX + 0x144) = 0;
  }
  else if (uVar10 <= *(uint *)(in_ECX + 0x144)) {
    *(uint *)(in_ECX + 0x144) = uVar10 - 1;
  }
  local_3c = 0;
  uVar10 = *(int *)(in_ECX + 0x144) * 0xf;
  if (uVar10 < uVar2) {
    piVar9 = (int *)(in_ECX + 0xfc);
    do {
      if (0xe < local_3c) {
        ExceptionList = local_14;
        return;
      }
      if (uVar10 < *(uint *)(iVar5 + 0x50d0)) {
        uVar7 = uVar10;
        FUN_00542210(uVar10);
        piVar6 = (int *)FUN_0050b4b0(uVar7);
        iVar8 = 0;
        if ((int *)*piVar6 != (int *)0x0) {
          iVar8 = *(int *)*piVar6;
        }
        uVar7 = piVar6[2];
        if (*(uint *)(iVar8 + 8) <= uVar7) {
          uVar7 = uVar7 - *(uint *)(iVar8 + 8);
        }
        iVar8 = *(int *)(*(int *)(iVar8 + 4) + uVar7 * 4);
        if (iVar8 != 0) {
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c = 1;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c = 0xffffffff;
          }
          iVar3 = *(int *)(iVar8 + 0xc);
          piVar6 = (int *)*piVar9;
          bVar1 = *(byte *)(iVar8 + 0x12);
          piVar6[0x9c] = (uint)*(byte *)(iVar8 + 0x11);
          piVar6[0x9d] = iVar3 + 0x93a80;
          pcVar4 = *(code **)(*piVar6 + 200);
          *(undefined1 *)((int)piVar6 + 0x269) = 1;
          piVar6[0x9b] = (uint)bVar1;
          (*pcVar4)();
          local_3c = local_3c + 1;
          piVar9 = piVar9 + 1;
        }
      }
      uVar10 = uVar10 + 1;
    } while (uVar10 < uVar2);
  }
  ExceptionList = local_14;
  return;
}

