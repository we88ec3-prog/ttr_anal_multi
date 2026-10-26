
void FUN_006557d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  uint uVar7;
  undefined2 in_FPUControlWord;
  undefined4 uStack_84;
  uint local_80;
  int local_7c;
  longlong local_78;
  int local_70;
  uint local_6c;
  uint local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  int *local_50;
  undefined4 local_4c;
  undefined1 local_48 [12];
  int *piStack_3c;
  int *local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0090aa5d;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_84;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffff70;
  ExceptionList = &local_14;
  FUN_00744640(param_1,param_2);
  if (*(int *)(*(int *)(in_ECX + 0x24) + 0x1c) != 0) {
    _eh_vector_constructor_iterator_
              (local_48,0x14,2,(_func_void_void_ptr *)&LAB_0074d950,FUN_005f5d10);
    piVar6 = (int *)0x0;
    local_20 = (int *)0x0;
    local_c = 0;
    local_70 = 0;
    if (0 < *(int *)(in_ECX + 0xd4)) {
      local_7c = 0;
      do {
        uVar7 = 0;
        if (*(int *)(*(int *)(in_ECX + 0xd8) + 4 + local_7c) -
            *(int *)(*(int *)(in_ECX + 0xd8) + local_7c) >> 3 != 0) {
          local_50 = (int *)0x3f800000;
          local_4c = 0x3f800000;
          do {
            uVar3 = (-(uint)(local_70 != *(int *)(in_ECX + 0xcc)) & 0x7878) - 0x10000;
            local_64 = (float)(uVar3 >> 0x10 & 0xff) * 0.003921569;
            local_60 = (float)(uVar3 >> 8 & 0xff) * 0.003921569;
            local_5c = (float)(uVar3 & 0xff) * 0.003921569;
            local_58 = (float)(uVar3 >> 0x18) * 0.003921569;
            if (local_64 < 1.0) {
              if (0.0 < local_64) {
                uStack_84 = (void *)CONCAT22(in_FPUControlWord,(undefined2)uStack_84);
                local_78 = (longlong)ROUND(local_64 * 255.0 + 0.5);
                local_6c = (uint)local_78;
              }
              else {
                local_6c = 0;
              }
            }
            else {
              local_6c = 0xff;
            }
            if (local_60 < 1.0) {
              if (0.0 < local_60) {
                uStack_84 = (void *)CONCAT22(in_FPUControlWord,(undefined2)uStack_84);
                local_78 = (longlong)ROUND(local_60 * 255.0 + 0.5);
                local_68 = (uint)local_78;
              }
              else {
                local_68 = 0;
              }
            }
            else {
              local_68 = 0xff;
            }
            if (local_5c < 1.0) {
              if (0.0 < local_5c) {
                uStack_84 = (void *)CONCAT22(in_FPUControlWord,(undefined2)uStack_84);
                local_78 = (longlong)ROUND(local_5c * 255.0 + 0.5);
                local_80 = (uint)local_78;
              }
              else {
                local_80 = 0;
              }
            }
            else {
              local_80 = 0xff;
            }
            if (local_58 < 1.0) {
              if (0.0 < local_58) {
                uStack_84 = (void *)CONCAT22(in_FPUControlWord,(undefined2)uStack_84);
                local_78 = (longlong)ROUND(local_58 * 255.0 + 0.5);
                iVar4 = (uint)local_78;
              }
              else {
                iVar4 = 0;
              }
            }
            else {
              iVar4 = 0xff;
            }
            iVar1 = *(int *)(*(int *)(in_ECX + 0xd8) + local_7c);
            FUN_00776de0(local_48,(int)*(float *)(iVar1 + uVar7 * 8),
                         (int)*(float *)(iVar1 + 4 + uVar7 * 8),
                         (int)*(float *)(*(int *)(*(int *)(in_ECX + 0xe8) + local_7c) + uVar7 * 8 +
                                        4),param_1,param_2,
                         ((iVar4 << 8 | local_6c) << 8 | local_68) << 8 | local_80,local_50,local_4c
                        );
            piVar6 = *(int **)(*(int *)(in_ECX + 0x24) + 0x1c);
            (**(code **)(*piVar6 + 0x68))(piVar6,0x28,0,0x44,1,&local_20,0);
            iVar4 = (**(code **)(*piStack_3c + 0x2c))(piStack_3c,0,0x28,&local_70,0);
            if (-1 < iVar4) {
              FID_conflict__memcpy(uStack_84,&local_78,0x28);
              (**(code **)(*local_50 + 0x30))(local_50);
            }
            (**(code **)(*piVar6 + 400))(piVar6,0,local_50,0,0x14);
            (**(code **)(*piVar6 + 0x164))(piVar6,0x44);
            (**(code **)(*piVar6 + 0x144))(piVar6,2,0,1);
            if (local_20 != (int *)0x0) {
              (**(code **)(*local_20 + 8))(local_20);
              local_20 = (int *)0x0;
            }
            piVar5 = (int *)(*(int *)(in_ECX + 0xd8) + local_7c);
            uVar7 = uVar7 + 1;
            piVar6 = local_20;
          } while (uVar7 < (uint)(piVar5[1] - *piVar5 >> 3));
        }
        local_70 = local_70 + 1;
        local_7c = local_7c + 0x10;
      } while (local_70 < *(int *)(in_ECX + 0xd4));
    }
    local_c = 1;
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 8))(piVar6,uVar2);
      local_20 = (int *)0x0;
    }
    local_c = 0xffffffff;
    _eh_vector_destructor_iterator_(local_48,0x14,2,FUN_005f5d10);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&uStack_84);
  return;
}

