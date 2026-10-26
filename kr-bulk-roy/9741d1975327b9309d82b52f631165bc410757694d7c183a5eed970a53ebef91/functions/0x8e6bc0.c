
void FUN_008e6bc0(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int local_140;
  int local_138;
  int local_134;
  int *local_130;
  int local_12c;
  int local_128 [60];
  int local_38 [12];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(param_1 + 100);
  local_12c = 0;
  (*(code *)param_2[0xf])(param_2,local_38,4,&local_138);
  if (local_138 < 0) {
    iVar4 = 0xa2;
  }
  else {
    if ((local_138 == 0) || (4 < local_138)) {
LAB_008e6da1:
      param_2[3] = 3;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    iVar2 = *param_2;
    iVar3 = param_2[2];
    iVar4 = FUN_008e5ee0(param_1,local_138);
    local_12c = iVar4;
    if (iVar4 == 0) {
      local_140 = 0;
      local_12c = 0;
      if (0 < local_138) {
        local_130 = local_38;
        piVar7 = (int *)(*(int *)(param_1 + 0x210) + 0x60);
        do {
          iVar4 = local_130[1];
          *param_2 = *local_130;
          param_2[2] = iVar4;
          (*(code *)param_2[0xf])(param_2,local_128,0x14,&local_134);
          if ((local_134 < 1) || (0x14 < local_134)) goto LAB_008e6da1;
          iVar4 = FUN_008bc7d0(uVar1,4,0,local_134 * 2,0,&local_12c);
          piVar7[-1] = iVar4;
          if (local_12c != 0) {
            param_2[3] = local_12c;
            __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
            return;
          }
          iVar8 = 0;
          *piVar7 = iVar4 + local_134 * 4;
          *(char *)(piVar7 + -2) = (char)local_134;
          if (0 < local_134) {
            piVar5 = local_128;
            do {
              iVar4 = piVar5[1];
              *param_2 = *piVar5 + 1;
              param_2[2] = iVar4 + -1;
              uVar6 = (*(code *)param_2[9])(param_2);
              *(undefined4 *)(piVar7[-1] + iVar8 * 4) = uVar6;
              uVar6 = (*(code *)param_2[10])(param_2,0);
              piVar5 = piVar5 + 3;
              *(undefined4 *)(*piVar7 + iVar8 * 4) = uVar6;
              iVar8 = iVar8 + 1;
            } while (iVar8 < local_134);
          }
          local_130 = local_130 + 3;
          local_140 = local_140 + 1;
          piVar7 = piVar7 + 3;
        } while (local_140 < local_138);
      }
      *param_2 = iVar2;
      param_2[2] = iVar3;
      param_2[3] = local_12c;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  param_2[3] = iVar4;
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

