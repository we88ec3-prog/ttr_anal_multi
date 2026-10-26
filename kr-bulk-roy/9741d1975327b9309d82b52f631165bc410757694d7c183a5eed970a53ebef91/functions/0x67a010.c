
void FUN_0067a010(void)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iStack_98;
  int iStack_94;
  int local_90;
  undefined1 auStack_8c [44];
  int iStack_60;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093ecd3;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&iStack_98;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff60;
  ExceptionList = &local_14;
  local_90 = in_ECX;
  cVar2 = FUN_00679e10(in_ECX);
  if (cVar2 != '\0') {
    (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(0,uVar3);
    if ((*(char *)(in_ECX + 0x124) == '\0') && (*(char *)(in_ECX + 0x125) == '\0')) {
      FUN_00679220();
    }
    else {
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        uStack_c = 0;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        uStack_c = 0xffffffff;
      }
      iStack_98 = 0x1b4;
      FUN_005740f0(&iStack_98);
      if (iStack_94 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)(iStack_94 + 0x10);
      if (7 < *(uint *)(iStack_94 + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      FUN_007572f0(puVar4);
      uStack_c._0_1_ = 1;
      uStack_c._1_3_ = 0;
      iStack_94 = 0;
      FUN_00848020(&iStack_94);
      if (iStack_98 != iStack_60) {
        *(undefined4 *)(iStack_98 + 0x18) = 0xffff0000;
        *(undefined1 *)(iStack_98 + 0x1c) = 1;
        FUN_007591a0(*(int *)(iStack_98 + 0x10),
                     *(int *)(iStack_98 + 0x14) - *(int *)(iStack_98 + 0x10),0xffff0000);
      }
      FUN_00759ac0(0);
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf4423;
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        uStack_c._0_1_ = 2;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        uStack_c._0_1_ = 1;
      }
      iStack_94 = 0x196;
      FUN_005740f0(&iStack_94);
      if (iStack_98 == DAT_00fe5b10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar5 = (undefined4 *)(iStack_98 + 0x10);
      if (7 < *(uint *)(iStack_98 + 0x24)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      FUN_007572f0(puVar5);
      uStack_c._0_1_ = 3;
      FUN_00407330(0xd1,auStack_8c,auStack_54,puVar4,local_90);
      uStack_c = CONCAT31(uStack_c._1_3_,1);
      FUN_00757640(auStack_54);
      uStack_c = 0xffffffff;
      FUN_00757640(auStack_8c);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&iStack_98);
  return;
}

