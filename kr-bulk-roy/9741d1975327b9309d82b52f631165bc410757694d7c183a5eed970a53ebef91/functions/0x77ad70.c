
void FUN_0077ad70(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  int local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_44;
  local_44 = param_1;
  if ((*(int *)(*(int *)(in_ECX + 8) + 0x24) != 0) &&
     (piVar1 = *(int **)(in_ECX + 0x10), piVar1 != (int *)0x0)) {
    iVar2 = piVar1[2];
    if (iVar2 != 0) {
      local_38 = *(undefined4 *)(iVar2 + 0x58);
      local_34 = 0x3f800000;
      iVar5 = *(int *)(in_ECX + 8) + 8;
      local_44 = *(int *)(iVar2 + 0x5c);
      local_30 = 0x3f800000;
      local_2c = 0;
      local_28 = (float)param_1;
      local_24 = (float)param_2;
      local_20 = 0;
      uStack_40 = (**(code **)(**(int **)(iVar2 + 8) + 0x10))();
      uStack_3c = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x24);
      puVar6 = &local_34;
      uVar4 = (**(code **)(*piVar1 + 0x2c))
                        (auStack_1c,*(undefined4 *)(in_ECX + 0x50),*(undefined1 *)(in_ECX + 0x4c),
                         iVar5,puVar6);
      FUN_00751850(uStack_3c,local_38,local_44,uVar4,iVar5,puVar6);
    }
    cVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(*(undefined4 *)(in_ECX + 0x50));
    if ((cVar3 == '\0') || (*(char *)(in_ECX + 0x4c) != '\0')) {
      FUN_0074e480(in_ECX);
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_44);
  return;
}

