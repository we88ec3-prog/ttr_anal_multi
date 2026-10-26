
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_00411bd0(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  undefined1 local_101c [8];
  undefined2 local_1014;
  undefined4 local_1010;
  uint local_100c;
  undefined2 local_1008 [2046];
  uint local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = **(int **)(unaff_ESI + 0x138);
  local_1010 = CONCAT13(*(undefined1 *)(unaff_ESI + 0x145),
                        CONCAT12(*(undefined1 *)(unaff_ESI + 0x144),0xd6));
  local_100c = local_1010;
  local_c = 4;
  iVar3 = 0;
  do {
    if (iVar1 == *(int *)(unaff_ESI + 0x138)) break;
    local_1014 = *(undefined2 *)(iVar1 + 0x10);
    local_1010 = CONCAT22(local_1010._2_2_,local_1014);
    if (local_c + 6 < 0x1001) {
      *(uint *)((int)local_1008 + (local_c - 4)) = (uint)*(ushort *)(iVar1 + 0xc);
      *(undefined2 *)((int)local_1008 + local_c) = local_1014;
      local_c = local_c + 6;
    }
    piVar2 = (int *)FUN_007b6890(unaff_ESI + 0x134,local_101c,iVar1);
    iVar1 = *piVar2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 10);
  if (4 < local_c) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,local_c);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

