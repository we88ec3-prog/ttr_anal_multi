
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0040a0d0(void)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined2 local_1010;
  undefined4 local_100c;
  undefined2 local_1008;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar1 = *(int *)(in_ECX + 0x100);
  iVar6 = 0;
  local_100c = 0xf8;
  local_1008 = 0;
  local_c = 6;
  iVar5 = *(int *)(iVar1 + 0xf4) - *(int *)(iVar1 + 0xf0) >> 2;
  if (0 < iVar5) {
    do {
      cVar2 = FUN_00408780(iVar1,iVar6);
      if (cVar2 != '\0') {
        uVar3 = FUN_004084f0(iVar1,iVar6);
        uVar4 = FUN_00408580(iVar1,iVar6);
        local_1010 = CONCAT11(uVar4,uVar3);
        if (local_c + 2U < 0x1001) {
          *(undefined2 *)((int)&local_100c + local_c) = local_1010;
          local_c = local_c + 2;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar5);
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,local_c);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

