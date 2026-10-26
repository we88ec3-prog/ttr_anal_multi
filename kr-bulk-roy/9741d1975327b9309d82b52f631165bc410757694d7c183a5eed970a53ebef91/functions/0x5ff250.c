
void FUN_005ff250(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  int *piVar5;
  undefined8 uVar6;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar2 = in_ECX[0x3c];
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar1 = DAT_00f94300;
  local_c = 0xffffffff;
  if ((iVar2 == 1) && (DAT_00f94300 != -0x16f8)) {
    local_20 = 1;
    iVar2 = (**(code **)(*in_ECX + 0x198))();
    if (0 < iVar2) {
      piVar5 = (int *)(iVar1 + 0x1720);
      do {
        if (*(int *)(iVar1 + 0x2398) < local_20) {
          FUN_005dd480();
        }
        else {
          if (local_20 - 1U < 100) {
            if (((piVar5[1] != 0) && (iVar2 = *piVar5, iVar2 != 0)) && (piVar5 != (int *)0x8)) {
              uVar6 = __allshl();
              uVar3 = (uint)uVar6 & in_ECX[0x42] | (uint)((ulonglong)uVar6 >> 0x20) & in_ECX[0x43];
              if (uVar3 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = CONCAT31((int3)(uVar3 >> 8),1);
              }
              FUN_005dd3c0(piVar5[2],piVar5[3],iVar2,(char)piVar5[4],uVar4);
              goto LAB_005ff3e2;
            }
          }
          else {
            FUN_006edb60(&DAT_00c0ddc0);
          }
          FUN_005dd3c0(0,0,0,0,(in_ECX[0x42] & in_ECX[0x43]) == 0xffffffff);
        }
LAB_005ff3e2:
        local_20 = local_20 + 1;
        piVar5 = piVar5 + 8;
        iVar2 = (**(code **)(*in_ECX + 0x198))();
      } while (local_20 <= iVar2);
    }
  }
  ExceptionList = local_14;
  return;
}

