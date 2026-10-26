
void FUN_00755810(int *param_1,int param_2,int param_3,int param_4,int param_5,int *param_6)

{
  undefined4 uVar1;
  BOOL BVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  float local_48;
  float local_44;
  int *local_40;
  int *local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  char local_2a;
  char local_29;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  piVar5 = param_6;
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  iVar3 = *(int *)(in_ECX + 0x24);
  local_30 = param_1;
  local_3c = param_6;
  if (iVar3 == 0) {
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  local_29 = '\0';
  if ((*(uint *)(in_ECX + 0x28) >> 0xe & 1) == 0) {
    local_38 = *(int *)(iVar3 + 8);
    uVar1 = *(undefined4 *)(iVar3 + 0xc);
    local_44 = (float)FUN_008fed10();
    uVar4 = FUN_008fed10();
    local_28.bottom = 0;
    local_28.right = 0;
    local_28.top = 0;
    local_28.left = 0;
    piVar6 = (int *)*local_30;
    local_34 = (int *)*piVar6;
    local_2a = '\0';
    local_40 = piVar6;
    if (local_34 == piVar6) goto LAB_00755ad0;
    do {
      BVar2 = IntersectRect(&local_28,(RECT *)(local_34 + 2),(RECT *)&param_2);
      if (BVar2 != 0) {
        if (local_2a == '\0') {
          FUN_00755370(local_38,uVar1,param_4 - param_2,param_5 - param_3,
                       *(int *)(in_ECX + 0x2c) - param_2,*(int *)(in_ECX + 0x30) - param_3);
          local_2a = '\x01';
          piVar5 = local_3c;
        }
        local_30 = (int *)*piVar5;
        iVar3 = FUN_0074d550(local_30,local_30[1]);
        if (piVar5[1] == 0xffffffe) {
LAB_0075595a:
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("list<T> too long");
        }
        piVar5[1] = piVar5[1] + 1;
        local_30[1] = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
        local_30 = (int *)local_28.left;
        local_18.right = (LONG)(float)local_28.left;
        local_28.right = local_28.right + -param_2;
        local_28.left = local_28.left + -param_2;
        local_18.bottom = (LONG)(float)local_28.top;
        local_28.bottom = local_28.bottom + -param_3;
        local_28.top = local_28.top + -param_3;
        FUN_00751520(local_44,uVar4,&local_18.right,*(int *)(in_ECX + 0x24) + 0x139c,
                     *(undefined4 *)(in_ECX + 0x80));
        local_29 = '\x01';
        piVar6 = local_40;
        piVar5 = local_3c;
      }
      local_34 = (int *)*local_34;
    } while (local_34 != piVar6);
  }
  else {
    local_40 = (int *)*param_1;
    local_18.bottom = 0;
    local_18.right = 0;
    local_18.top = 0;
    local_18.left = 0;
    piVar5 = (int *)*local_40;
    piVar6 = param_6;
    local_34 = piVar5;
    if (piVar5 == local_40) goto LAB_00755ad0;
    do {
      local_34 = piVar5;
      BVar2 = IntersectRect(&local_18,(RECT *)(piVar5 + 2),(RECT *)&param_2);
      if (BVar2 != 0) {
        local_38 = *piVar6;
        iVar3 = FUN_0074d550(local_38,*(undefined4 *)(local_38 + 4));
        if (piVar6[1] == 0xffffffe) goto LAB_0075595a;
        piVar6[1] = piVar6[1] + 1;
        *(int *)(local_38 + 4) = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
        local_18.right = local_18.right - *(int *)(in_ECX + 0x2c);
        local_38 = local_18.left;
        local_48 = (float)local_18.left;
        local_18.left = local_18.left - *(int *)(in_ECX + 0x2c);
        local_18.bottom = local_18.bottom - *(int *)(in_ECX + 0x30);
        local_30 = (int *)local_18.top;
        local_44 = (float)local_18.top;
        local_18.top = local_18.top - *(int *)(in_ECX + 0x30);
        FUN_00751520(*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 8),
                     *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0xc),&local_48,
                     *(int *)(in_ECX + 0x24) + 0x139c,*(undefined4 *)(in_ECX + 0x80));
        local_29 = '\x01';
        piVar5 = local_34;
        piVar6 = local_3c;
      }
      piVar5 = (int *)*piVar5;
      local_34 = piVar5;
    } while (piVar5 != local_40);
  }
  if (local_29 != '\0') {
    FUN_00751800();
  }
LAB_00755ad0:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

