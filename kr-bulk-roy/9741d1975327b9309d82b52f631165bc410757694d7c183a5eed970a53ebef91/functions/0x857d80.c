
undefined4 FUN_00857d80(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iStack_38;
  int *piStack_34;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 local_1c [6];
  
  uVar1 = *(uint *)(param_2 + 0x84);
  piStack_34 = (int *)0x0;
  iStack_38 = 4;
  local_1c[0] = 0;
  FUN_006ddcc0();
  FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&stack0xffffffd0,4,0);
  if ((&stack0x00000000 != (undefined1 *)0x1c) && (uVar1 != 0)) {
    FUN_00857f80();
    piStack_34 = param_1 + 4;
    FUN_00858020();
    uVar4 = 0;
    if (uVar1 != 0) {
      iVar6 = 0;
      do {
        iStack_38 = 0;
        FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),&iStack_38,4,0);
        FUN_00858120();
        iVar3 = *(int *)(iVar6 + *piStack_34);
        iVar2 = iStack_38;
        if (0 < iStack_38) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),iVar3,8,0);
            iVar3 = iVar3 + 8;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
        uVar4 = uVar4 + 1;
        iVar6 = iVar6 + 0x10;
      } while (uVar4 < uVar1);
    }
    iVar6 = 0;
    puVar5 = (undefined4 *)0x0;
    if (&stack0x00000000 != (undefined1 *)0x1c) {
      do {
        FUN_0084fba0();
        iVar3 = *(int *)(iVar6 + *param_1);
        uVar4 = uVar1;
        if (0 < (int)uVar1) {
          do {
            FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),iVar3,0xc,0);
            iVar3 = iVar3 + 0xc;
            uVar4 = uVar4 - 1;
          } while (uVar4 != 0);
        }
        FUN_006ddcc0(*(undefined4 *)(param_2 + 0x84),iVar6 + 0x10 + *param_1,4,0);
        puVar5 = (undefined4 *)((int)puVar5 + 1);
        iVar6 = iVar6 + 0x14;
      } while (puVar5 < local_1c);
    }
    return 1;
  }
  return 0;
}

