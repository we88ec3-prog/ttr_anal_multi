
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_004775b0(undefined2 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  undefined2 local_1010;
  undefined2 local_100c [2048];
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar2 = 4;
  local_100c[0] = 0xf6;
  local_100c[1] = param_1;
  local_c = 4;
  piVar3 = (int *)(in_ECX + 0xf4);
  iVar4 = 10;
  do {
    iVar1 = *piVar3;
    if (*(int *)(iVar1 + 0x250) != 0) {
      local_1010 = CONCAT11(*(undefined1 *)(iVar1 + 0x2a0),*(undefined1 *)(iVar1 + 0x29c));
      if (iVar2 + 2U < 0x1001) {
        *(undefined2 *)((int)local_100c + iVar2) = local_1010;
        iVar2 = local_c + 2;
        local_c = iVar2;
      }
    }
    piVar3 = piVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  (**(code **)(*DAT_00fba854 + 0x10))(0,local_100c,iVar2);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

