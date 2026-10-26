
/* WARNING: Removing unreachable block (ram,0x00849ac1) */
/* WARNING: Removing unreachable block (ram,0x00849ad0) */
/* WARNING: Removing unreachable block (ram,0x00849ad2) */
/* WARNING: Removing unreachable block (ram,0x00849ad6) */
/* WARNING: Removing unreachable block (ram,0x00849aec) */
/* WARNING: Removing unreachable block (ram,0x00849af0) */
/* WARNING: Removing unreachable block (ram,0x00849aff) */
/* WARNING: Removing unreachable block (ram,0x00849b01) */
/* WARNING: Removing unreachable block (ram,0x00849b05) */
/* WARNING: Removing unreachable block (ram,0x00849b1b) */
/* WARNING: Removing unreachable block (ram,0x00849b20) */
/* WARNING: Removing unreachable block (ram,0x00849b2f) */
/* WARNING: Removing unreachable block (ram,0x00849b31) */

void FUN_00849a90(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x24) != *(int *)(param_1 + 0x28)) {
    uVar1 = FUN_004fa270(*(int *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x28) = uVar1;
  }
  if (*(int *)(param_1 + 0x34) != *(int *)(param_1 + 0x38)) {
    *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x34);
  }
  if (*(int *)(param_1 + 4) != *(int *)(param_1 + 8)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 4);
  }
  if (*(int *)(param_1 + 0x14) != *(int *)(param_1 + 0x18)) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x14);
  }
  return;
}

