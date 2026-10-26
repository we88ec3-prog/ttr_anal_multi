
undefined4 FUN_004c8060(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  int *in_ECX;
  undefined4 in_XMM0_Da;
  int iStack_20;
  int *piStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00939603;
  local_14 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if (in_ECX[0xdc] != 0) {
    piVar2 = in_ECX + 0x57;
    in_ECX[0xdc] = 0;
    piVar3 = (int *)in_ECX[0x58];
    in_ECX[0x58] = 0;
    *piVar2 = 0;
    if (piVar3 != (int *)0x0) {
      LOCK();
      iVar5 = piVar3[1] + -1;
      piVar3[1] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)*piVar3)(uVar6);
        LOCK();
        iVar5 = piVar3[2] + -1;
        piVar3[2] = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
    uVar6 = in_ECX[0x23];
    if (uVar6 == 0) {
      uVar6 = in_ECX[0x22];
    }
    iStack_20 = FUN_00891268(0x170);
    uStack_c = 0;
    if (iStack_20 == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = FUN_007a4c50(iStack_20,uVar6 & 0xffff);
    }
    uStack_c = 0xffffffff;
    iStack_20 = 0;
    piStack_1c = (int *)0x0;
    FUN_004ca460(&iStack_20,uVar7);
    uStack_c = 1;
    FUN_004e0f60();
    piVar3 = piStack_1c;
    uStack_c = 0xffffffff;
    if (piStack_1c != (int *)0x0) {
      LOCK();
      iVar5 = piStack_1c[1] + -1;
      piStack_1c[1] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        (**(code **)*piStack_1c)();
        piVar1 = piVar3 + 2;
        LOCK();
        iVar5 = *piVar1 + -1;
        *piVar1 = iVar5;
        UNLOCK();
        if (iVar5 == 0) {
          (**(code **)(*piVar3 + 4))();
        }
      }
    }
    FUN_007a6ea0(*piVar2,1,(short)in_ECX[0xe2]);
    pcVar4 = *(code **)(*in_ECX + 0x44);
    in_ECX[0xdc] = 1;
    (*pcVar4)(in_ECX + 0x28,1);
    (**(code **)(*in_ECX + 0x58))((char)in_ECX[0x2c]);
    if (((in_ECX[0xea] == 0) && (*(char *)(in_ECX + 0xe9) = (char)in_ECX[0x2c], in_ECX[0xdc] != 0))
       && (*piVar2 != 0)) {
      iVar5 = *(int *)(*piVar2 + 4);
      FUN_00444a90((char)in_ECX[0x2c]);
      (**(code **)(iVar5 + 0xc))(in_XMM0_Da);
    }
    (**(code **)(*in_ECX + 0x5c))(in_ECX[0x2d]);
    (**(code **)(*in_ECX + 0x68))(in_ECX[0xe3],0x3f800000);
  }
  ExceptionList = local_14;
  return 1;
}

