
void FUN_00778760(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  float *pfVar7;
  float *pfVar8;
  undefined4 uVar9;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int *local_38;
  int local_34;
  int local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  undefined1 local_1c [16];
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_44;
  local_34 = param_1;
  if ((*(int *)(in_ECX + 8) != 0) &&
     (local_3c = *(int *)(*(int *)(in_ECX + 8) + 0x24), local_3c != 0)) {
    piVar5 = (int *)(in_ECX + 0x10);
    if (*(int *)(in_ECX + 0x10) != 0) {
      iVar4 = *(int *)(*(int *)(in_ECX + 0x10) + 8);
      local_30 = iVar4;
      if (iVar4 != 0) {
        piVar6 = (int *)(in_ECX + 600);
        local_40 = 9;
        do {
          piVar1 = (int *)*piVar5;
          local_38 = piVar5;
          if (piVar1 != (int *)0x0) {
            uVar2 = *(undefined4 *)(iVar4 + 0x5c);
            local_44 = *(undefined4 *)(iVar4 + 0x58);
            local_2c = (float)(piVar6[-1] - piVar6[-3]) / (float)(piVar1[0xc] - piVar1[10]);
            local_28 = (float)(*piVar6 - piVar6[-2]) / (float)(piVar1[0xd] - piVar1[0xb]);
            local_24 = (float)(piVar6[-3] + local_34);
            pfVar8 = &local_2c;
            local_20 = (float)(piVar6[-2] + param_2);
            pfVar7 = &local_24;
            uVar9 = 0x3f800000;
            (**(code **)(*piVar1 + 0x2c))
                      (local_1c,*(undefined4 *)(in_ECX + 0x2f0),*(undefined1 *)(in_ECX + 0x2ec),
                       pfVar7,pfVar8,0x3f800000);
            FUN_00751230(local_44,uVar2,pfVar7,pfVar8,uVar9);
            iVar4 = local_30;
          }
          piVar5 = local_38 + 0x10;
          piVar6 = piVar6 + 4;
          local_40 = local_40 + -1;
        } while (local_40 != 0);
        local_38 = piVar5;
        (**(code **)(**(int **)(iVar4 + 8) + 0x10))();
        FUN_00751800();
      }
      cVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(*(undefined4 *)(in_ECX + 0x2f0));
      if ((cVar3 == '\0') || (*(char *)(in_ECX + 0x2ec) != '\0')) {
        FUN_0074e480(in_ECX);
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&local_44);
  return;
}

