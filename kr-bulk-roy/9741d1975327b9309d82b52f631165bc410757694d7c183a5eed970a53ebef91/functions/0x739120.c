
/* WARNING: Removing unreachable block (ram,0x0073914e) */
/* WARNING: Removing unreachable block (ram,0x00739150) */
/* WARNING: Removing unreachable block (ram,0x0073915f) */
/* WARNING: Removing unreachable block (ram,0x00739161) */
/* WARNING: Removing unreachable block (ram,0x00739165) */

void FUN_00739120(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (*(int *)(param_1 + 0x10) != *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x10);
  }
  return;
}

