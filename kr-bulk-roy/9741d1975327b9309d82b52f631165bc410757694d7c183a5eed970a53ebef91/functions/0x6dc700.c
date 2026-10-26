
/* WARNING: Removing unreachable block (ram,0x006dc763) */
/* WARNING: Removing unreachable block (ram,0x006dc775) */
/* WARNING: Removing unreachable block (ram,0x006dc77e) */
/* WARNING: Removing unreachable block (ram,0x006dc7ad) */
/* WARNING: Removing unreachable block (ram,0x006dc7d3) */
/* WARNING: Removing unreachable block (ram,0x006dc7de) */
/* WARNING: Removing unreachable block (ram,0x006dc7e9) */
/* WARNING: Removing unreachable block (ram,0x006dc7ee) */
/* WARNING: Removing unreachable block (ram,0x006dc7f3) */
/* WARNING: Removing unreachable block (ram,0x006dc7fc) */
/* WARNING: Removing unreachable block (ram,0x006dc81d) */
/* WARNING: Removing unreachable block (ram,0x006dc847) */
/* WARNING: Removing unreachable block (ram,0x006dc84e) */
/* WARNING: Removing unreachable block (ram,0x006dc85e) */
/* WARNING: Removing unreachable block (ram,0x006dc868) */
/* WARNING: Removing unreachable block (ram,0x006dc86e) */

void FUN_006dc700(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009197a9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) != 0) {
    local_8 = 0;
    FUN_007a76b0(*(int *)(param_1 + 0x10));
  }
  ExceptionList = local_10;
  return;
}

