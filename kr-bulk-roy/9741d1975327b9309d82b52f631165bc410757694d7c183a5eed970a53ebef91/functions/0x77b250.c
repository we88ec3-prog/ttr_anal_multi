
void FUN_0077b250(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 uVar6;
  int in_ECX;
  float *pfVar7;
  float *pfVar8;
  int local_44;
  float local_40;
  float local_3c;
  int local_38;
  float local_34;
  float local_30;
  undefined4 local_2c;
  float local_28;
  float local_24;
  undefined4 local_20;
  undefined1 auStack_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_44;
  iVar1 = *(int *)(in_ECX + 8);
  local_38 = param_1;
  if ((*(int *)(iVar1 + 0x24) != 0) && (piVar2 = *(int **)(in_ECX + 0x10), piVar2 != (int *)0x0)) {
    iVar3 = piVar2[2];
    if (iVar3 != 0) {
      local_40 = 1.0;
      local_3c = 1.0;
      if (*(char *)(in_ECX + 0x4c) != '\0') {
        local_40 = (float)(*(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 8)) /
                   (float)(piVar2[0xc] - piVar2[10]);
        local_44 = piVar2[0xd] - piVar2[0xb];
        local_3c = (float)(*(int *)(iVar1 + 0x14) - *(int *)(iVar1 + 0xc)) / (float)local_44;
      }
      local_38 = *(int *)(iVar3 + 0x58);
      uVar4 = *(undefined4 *)(iVar3 + 0x5c);
      local_34 = local_40;
      local_30 = local_3c;
      local_2c = 0;
      local_28 = (float)param_1;
      local_24 = (float)param_2;
      local_20 = 0;
      local_44 = (**(code **)(**(int **)(iVar3 + 8) + 0x10))();
      local_40 = *(float *)(*(int *)(in_ECX + 8) + 0x24);
      pfVar8 = &local_34;
      pfVar7 = &local_28;
      uVar6 = (**(code **)(*piVar2 + 0x2c))
                        (auStack_1c,*(undefined4 *)(in_ECX + 0x50),*(undefined1 *)(in_ECX + 0x4d),
                         pfVar7,pfVar8);
      FUN_00750ec0(local_38,uVar4,uVar6,pfVar7,pfVar8);
    }
    cVar5 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(*(undefined4 *)(in_ECX + 0x50));
    if ((cVar5 == '\0') || (*(char *)(in_ECX + 0x4d) != '\0')) {
      FUN_0074e480(in_ECX);
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_44);
  return;
}

