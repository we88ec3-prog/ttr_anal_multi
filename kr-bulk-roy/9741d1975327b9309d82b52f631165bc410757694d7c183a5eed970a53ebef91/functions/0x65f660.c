
void FUN_0065f660(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int *piVar8;
  int local_28;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009461bc;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar2);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (((param_2 < 10) && (iVar3 = param_2 * 0x210 + DAT_00f94304, *(int *)(iVar3 + 0x5c) != 0)) &&
     (iVar3 != 0)) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar2);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((param_2 - 1 < 0xf) && (iVar5 = param_2 * 0x108 + DAT_00f94300, iVar5 != 0)) {
      piVar8 = (int *)(param_1 + 0x168);
      local_28 = 0x10;
      do {
        iVar7 = *piVar8;
        iVar1 = *(int *)(iVar7 + 0x29c);
        if (iVar1 == -1) {
LAB_0065f882:
          if (*(char *)(iVar7 + 0x2a8) == '\0') {
            FUN_005e0b80();
            (**(code **)(*(int *)*piVar8 + 200))();
          }
        }
        else {
          if (0xe < iVar1 - 1U) {
            FUN_006edb60(&DAT_00c0dddc,iVar1);
LAB_0065f880:
            iVar7 = *piVar8;
            goto LAB_0065f882;
          }
          piVar6 = (int *)(iVar1 * 0x10 + iVar5);
          if ((piVar6 == (int *)0x0) || (piVar6[2] == 0)) goto LAB_0065f880;
          iVar4 = FUN_005e06b0(param_2,piVar6[1],piVar6[2],piVar6[3]);
          iVar7 = *piVar8;
          if (((((*piVar6 != *(int *)(iVar7 + 0x250)) || (piVar6[1] != *(int *)(iVar7 + 0x254))) ||
               (piVar6[2] != *(int *)(iVar7 + 0x248))) ||
              ((piVar6[3] != *(int *)(iVar7 + 0x24c) ||
               ((uint)(iVar4 != 0) != (*(uint *)(*(int *)(iVar7 + 0x2a0) + 0x28) >> 8 & 1))))) ||
             (((*(uint *)(iVar3 + 0xf8) & 1 << ((byte)iVar1 & 0x1f)) == 0) !=
              (bool)((byte)(*(uint *)(*(int *)(iVar7 + 0x2a4) + 0x28) >> 9) & 1))) {
            (**(code **)(*(int *)*piVar8 + 0x19c))(*piVar6,piVar6[1],piVar6[2],piVar6[3]);
            (**(code **)(*(int *)*piVar8 + 200))();
          }
        }
        iVar7 = *piVar8;
        piVar8 = piVar8 + 1;
        local_28 = local_28 + -1;
        *(uint *)(iVar7 + 0x298) = param_2;
      } while (local_28 != 0);
    }
  }
  ExceptionList = local_14;
  return;
}

