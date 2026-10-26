
void FUN_006ec140(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_34;
  uint local_30;
  int *local_2c;
  undefined4 *local_28;
  undefined1 local_24 [12];
  undefined4 local_18;
  uint local_14 [4];
  
  local_14[3] = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_28 = param_2;
  local_14[0] = 1;
  local_14[1] = 3;
  local_14[2] = 2;
  local_30 = 0;
  local_34 = in_ECX;
  do {
    uVar1 = local_30;
    iVar3 = FUN_00891268(0x144);
    if (iVar3 == 0) {
      __security_check_cookie(local_14[3] ^ (uint)&stack0xfffffffc);
      return;
    }
    *(undefined4 *)(iVar3 + 0x138) = 0;
    *(undefined4 *)(iVar3 + 0x13c) = 0;
    *(undefined4 *)(iVar3 + 0x140) = 0;
    uVar1 = local_14[uVar1];
    *(uint *)(iVar3 + 4) = uVar1;
    iVar4 = (**(code **)(*(int *)*param_1 + 0x38))((int *)*param_1,*local_28,uVar1,iVar3 + 8);
    if (iVar4 < 0) {
LAB_006ec2a3:
      FUN_006ecae0();
      FUN_0089120c(iVar3);
    }
    else {
      (**(code **)(*(int *)*param_1 + 0x20))((int *)*param_1,0,local_24);
      _memset(&local_6c,0,0x38);
      local_6c = 1;
      local_68 = 1;
      local_64 = local_18;
      local_60 = 1;
      local_54 = 3;
      local_4c = 1;
      local_50 = FUN_006dfe10();
      local_2c = (int *)0x0;
      iVar4 = *(int *)*param_1;
      uVar5 = FUN_006dfe10(0x40,&local_6c,&local_2c);
      iVar4 = (**(code **)(iVar4 + 0x40))(*param_1,*local_28,*(undefined4 *)(iVar3 + 4),uVar5);
      if ((iVar4 < 0) && (iVar4 == -0x7789f796)) goto LAB_006ec2a3;
      if (local_2c != (int *)0x0) {
        (**(code **)(*local_2c + 8))(local_2c);
        local_2c = (int *)0x0;
      }
      puVar2 = local_28;
      iVar4 = FUN_006ec2f0(param_1,local_28,local_34);
      if ((iVar4 < 0) || (*(int *)(iVar3 + 0x13c) < 1)) goto LAB_006ec2a3;
      iVar4 = FUN_006ed1c0();
      if (-1 < iVar4) {
        *(int *)(puVar2[0x197] + puVar2[0x198] * 4) = iVar3;
        puVar2[0x198] = puVar2[0x198] + 1;
      }
    }
    local_30 = local_30 + 1;
    if (2 < local_30) {
      __security_check_cookie(local_14[3] ^ (uint)&stack0xfffffffc);
      return;
    }
  } while( true );
}

