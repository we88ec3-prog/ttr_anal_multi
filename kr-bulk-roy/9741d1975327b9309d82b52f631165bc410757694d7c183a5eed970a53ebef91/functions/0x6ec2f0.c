
void FUN_006ec2f0(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  uint local_3c;
  int local_38;
  int local_28;
  uint local_20 [7];
  
  local_20[6] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_20[0] = 0x15;
  local_20[1] = 0x16;
  local_20[2] = 0x23;
  local_20[3] = 0x17;
  local_20[4] = 0x19;
  local_20[5] = 0x18;
  local_38 = 0;
  if (0 < param_3[1]) {
    do {
      uVar1 = *(undefined4 *)(*param_3 + local_38 * 4);
      local_3c = 0;
      do {
        uVar2 = local_20[local_3c];
        local_28 = 0;
        do {
          if ((((local_28 != 0) || (param_2[0x195] != 0)) &&
              (iVar4 = (**(code **)(*(int *)*param_1 + 0x24))
                                 ((int *)*param_1,*param_2,*(undefined4 *)(in_ECX + 4),uVar1,uVar2,
                                  local_28), -1 < iVar4)) &&
             (((*(char *)(param_1 + 3) == '\0' ||
               (iVar4 = (**(code **)(*(int *)*param_1 + 0x28))
                                  ((int *)*param_1,*param_2,*(undefined4 *)(in_ECX + 4),uVar1,
                                   0x80000,3,uVar2), -1 < iVar4)) &&
              (((code *)param_1[1] == (code *)0x0 ||
               (cVar3 = (*(code *)param_1[1])(in_ECX + 8,uVar1,uVar2,local_28 != 0,param_1[2]),
               cVar3 != '\0')))))) {
            puVar5 = (undefined4 *)FUN_00891268(0x58);
            if (puVar5 == (undefined4 *)0x0) {
              __security_check_cookie(local_20[6] ^ (uint)&stack0xfffffffc);
              return;
            }
            puVar5[5] = 0;
            puVar5[6] = 0;
            puVar5[7] = 0;
            puVar5[8] = 0;
            puVar5[9] = 0;
            puVar5[10] = 0;
            puVar5[0xb] = 0;
            puVar5[0xc] = 0;
            puVar5[0xd] = 0;
            puVar5[0xe] = 0;
            puVar5[0xf] = 0;
            puVar5[0x10] = 0;
            puVar5[0x11] = 0;
            puVar5[0x12] = 0;
            puVar5[0x13] = 0;
            *puVar5 = *param_2;
            puVar5[1] = *(undefined4 *)(in_ECX + 4);
            puVar5[2] = uVar1;
            puVar5[3] = uVar2;
            puVar5[4] = (uint)(local_28 != 0);
            FUN_006ec5c0(param_1);
            FUN_006ec650(param_1);
            if (puVar5[9] == 0) {
              FUN_006ec530();
              FUN_0089120c(puVar5);
            }
            else {
              FUN_006ec700(param_1);
              FUN_006ec790(param_1,in_ECX,puVar5);
              puVar5[0x15] = in_ECX;
              puVar5[0x14] = param_2;
              iVar4 = FUN_006ed1c0();
              if (-1 < iVar4) {
                *(undefined4 **)(*(int *)(in_ECX + 0x138) + *(int *)(in_ECX + 0x13c) * 4) = puVar5;
                *(int *)(in_ECX + 0x13c) = *(int *)(in_ECX + 0x13c) + 1;
              }
            }
          }
          local_28 = local_28 + 1;
        } while (local_28 < 2);
        local_3c = local_3c + 1;
      } while (local_3c < 6);
      local_38 = local_38 + 1;
    } while (local_38 < param_3[1]);
  }
  __security_check_cookie(local_20[6] ^ (uint)&stack0xfffffffc);
  return;
}

