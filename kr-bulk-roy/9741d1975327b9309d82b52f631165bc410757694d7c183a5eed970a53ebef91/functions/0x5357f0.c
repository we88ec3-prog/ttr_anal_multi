
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005357f0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  undefined4 local_100c;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  Sleep(10);
  local_100c._2_1_ = 0;
  if (*(uint *)(unaff_ESI + 0x34) < 0x79) {
    local_100c._2_1_ = 2;
  }
  local_100c._0_2_ = 0xbd2;
  iVar3 = 3;
  local_c = 3;
  piVar2 = (int *)**(int **)(unaff_ESI + 0x30);
  uVar4 = 0;
  if (piVar2 != *(int **)(unaff_ESI + 0x30)) {
    do {
      if (0x78 < uVar4) break;
      if (iVar3 + 4U < 0x1001) {
        *(int *)((int)&local_100c + iVar3) = piVar2[2];
        iVar3 = local_c + 4;
        local_c = iVar3;
      }
      piVar1 = (int *)*piVar2;
      if (piVar2 != *(int **)(unaff_ESI + 0x30)) {
        *(int **)piVar2[1] = piVar1;
        *(int *)(*piVar2 + 4) = piVar2[1];
        FUN_0089120c(piVar2);
        *(int *)(unaff_ESI + 0x34) = *(int *)(unaff_ESI + 0x34) + -1;
        iVar3 = local_c;
      }
      uVar4 = uVar4 + 1;
      piVar2 = piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_ESI + 0x30));
  }
  (**(code **)(*DAT_00fba854 + 0x10))(2,&local_100c,iVar3);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

