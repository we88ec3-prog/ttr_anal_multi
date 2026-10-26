
/* WARNING: Removing unreachable block (ram,0x00655c7d) */

int * FUN_00655c30(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905c90;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar3 = param_2[1];
  iVar1 = *param_2;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (iVar3 - iVar1 != 0) {
    iVar2 = FUN_00407dc0();
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    param_1[2] = iVar2 + (iVar3 - iVar1);
    iVar3 = FUN_00655f70(*param_2,param_2[1],param_1);
    param_1[1] = iVar3;
  }
  ExceptionList = local_10;
  return param_1;
}

