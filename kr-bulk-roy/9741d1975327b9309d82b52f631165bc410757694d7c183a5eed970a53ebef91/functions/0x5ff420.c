
void FUN_005ff420(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 auStack_94 [4];
  int local_90;
  undefined1 local_8c [56];
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00943507;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_94;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  FUN_005f5ed0(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf436b:
    iVar2 = FUN_004068c0(uVar1);
    iVar5 = FUN_00412b10();
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      FUN_00601030(*(undefined4 *)(iVar5 + 0x14));
    }
    break;
  case 0xf436c:
    iVar2 = FUN_00412b10();
    FUN_00602430(*(undefined4 *)(iVar2 + 0x18));
    break;
  case 0xf4372:
    iVar2 = FUN_005c2300();
    FUN_00602020(in_ECX,*(undefined4 *)(iVar2 + 0x1c),*(undefined4 *)(iVar2 + 0x20));
    break;
  case 0xf4373:
    iVar2 = FUN_00412ae0();
    FUN_00601df0(in_ECX,*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x1c));
    break;
  case 0xf4374:
    iVar2 = FUN_00603e50();
    if (*(int *)(iVar2 + 0x14) == 0xf43a5) {
      FUN_00602270(*(undefined4 *)(iVar2 + 0x18),*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 4),
                   *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 8));
    }
    break;
  case 0xf4384:
    iVar2 = FUN_004068c0(uVar1);
    iVar5 = FUN_00412b10();
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      FUN_00603820(*(undefined4 *)(iVar5 + 0x14));
    }
    break;
  case 0xf4385:
    iVar2 = FUN_004068c0(uVar1);
    iVar5 = FUN_00412b10();
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      FUN_00414680();
      FUN_004a3d60(*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18));
    }
    break;
  case 0xf4387:
    iVar2 = FUN_004068c0(uVar1);
    iVar5 = FUN_00412b10();
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      FUN_00414680();
      FUN_004a3da0(*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18));
    }
    break;
  case 0xf439a:
    iVar2 = FUN_00603e50();
    if (*(int *)(iVar2 + 0x14) == 0xf43a5) {
      FUN_00602930(*(undefined4 *)(*(int *)(iVar2 + 0x1c) + 4),
                   *(undefined4 *)(*(int *)(iVar2 + 0x1c) + 8));
    }
    break;
  case 0xf43ae:
    iVar2 = FUN_004068c0(uVar1);
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      local_90 = FUN_00412ae0();
      if ((*(char *)(in_ECX + 0x159) == '\0') && (*(char *)(in_ECX + 0x158) == '\0')) {
        FUN_00602740(*(undefined4 *)(local_90 + 0x14),*(undefined4 *)(local_90 + 0x18),
                     *(undefined4 *)(local_90 + 0x1c));
      }
      else {
        uVar6 = 0xf2;
        FUN_005854b0(0xf2);
        uVar6 = FUN_00585330(uVar6);
        FUN_007572f0(uVar6);
        local_c = 0;
        FUN_00758d30();
        FUN_00759ac0(0);
        iVar2 = FUN_00891268(0x20);
        if (iVar2 == 0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_00753e30(0xf4424,*(undefined4 *)(local_90 + 0x18),
                               *(undefined4 *)(local_90 + 0x1c));
        }
        uVar7 = 0x196;
        FUN_005854b0(0x196);
        uVar7 = FUN_00585330(uVar7);
        FUN_007572f0(uVar7);
        local_c._0_1_ = 1;
        FUN_00407330(0xd1,local_8c,local_54,uVar6);
        local_c = (uint)local_c._1_3_ << 8;
        FUN_00757640(local_54);
        local_c = 0xffffffff;
        FUN_00757640(local_8c);
      }
    }
    break;
  case 0xf4424:
    iVar2 = FUN_004068c0(uVar1);
    if (*(int *)(iVar2 + 0x14) == 0x6a7) {
      iVar2 = FUN_00412ae0();
      FUN_00602740(*(undefined4 *)(iVar2 + 0x14),*(undefined4 *)(iVar2 + 0x18),
                   *(undefined4 *)(iVar2 + 0x1c));
    }
  case 0xf4383:
    iVar3 = FUN_004068c0(uVar1);
    iVar4 = FUN_00412ae0();
    iVar2 = *(int *)(iVar4 + 0x1c);
    iVar5 = *(int *)(iVar4 + 0x18);
    local_90 = *(int *)(iVar4 + 0x14);
    if ((((*(int *)(iVar3 + 0x14) == 0x6a7) && (local_90 != 0)) && (iVar5 != 0)) && (iVar2 != 0)) {
      FUN_00414680();
      FUN_004a39f0(local_90,iVar5,iVar2,0);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_94);
  return;
}

