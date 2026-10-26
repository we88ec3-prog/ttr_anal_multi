
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_0045c280(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char cVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined2 local_1018;
  undefined2 local_1014;
  short sStack_1012;
  undefined2 uStack_1010;
  undefined4 local_100c;
  undefined2 local_1008;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x100) + 0x254);
  sStack_1012 = (short)uVar1;
  uStack_1010 = (undefined2)((uint)uVar1 >> 0x10);
  local_100c = CONCAT22(sStack_1012,0xe0);
  iVar8 = 6;
  iVar2 = *(int *)(param_1 + 0x108);
  local_1008 = uStack_1010;
  local_c = 6;
  iVar6 = *(int *)(iVar2 + 0xf4) - *(int *)(iVar2 + 0xf0);
  iVar9 = 0;
  iVar7 = iVar6 >> 2;
  local_1014 = (undefined2)iVar7;
  sStack_1012 = (short)(iVar6 >> 0x12);
  if (0 < iVar7) {
    do {
      cVar3 = FUN_0045ae00(iVar9);
      if (cVar3 != '\0') {
        uVar4 = FUN_0045aa00(iVar2,iVar9);
        uVar5 = FUN_0045aa90(iVar2,iVar9);
        local_1018 = CONCAT11(uVar5,uVar4);
        uVar4 = FUN_0045ad70(iVar2,iVar9);
        if (iVar8 + 3U < 0x1001) {
          *(undefined2 *)((int)&local_100c + iVar8) = local_1018;
          *(undefined1 *)((int)&local_100c + iVar8 + 2) = uVar4;
          iVar8 = local_c + 3;
          local_c = iVar8;
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < CONCAT22(sStack_1012,local_1014));
  }
  (**(code **)(*DAT_00fba854 + 0x10))(0,&local_100c,iVar8);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

