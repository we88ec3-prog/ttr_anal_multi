
int FUN_004c7b90(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 *in_ECX;
  int *piVar4;
  int iVar5;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0090d9b9;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CActor::vftable;
  in_ECX[0x3c] = CActor::vftable;
  local_8 = 4;
  iVar3 = in_ECX[0xda];
  if (iVar3 != 0) {
    local_8._0_1_ = 5;
    local_8._1_3_ = 0;
    FUN_00833ad0(**(undefined4 **)(iVar3 + 4),*(undefined4 **)(iVar3 + 4));
    local_8 = CONCAT31(local_8._1_3_,4);
    FUN_0089120c(*(undefined4 *)(iVar3 + 4));
    FUN_0089120c(iVar3);
    in_ECX[0xda] = 0;
  }
  piVar4 = (int *)in_ECX[0x58];
  in_ECX[0x58] = 0;
  in_ECX[0x57] = 0;
  if (piVar4 != (int *)0x0) {
    LOCK();
    iVar3 = piVar4[1] + -1;
    piVar4[1] = iVar3;
    UNLOCK();
    if (iVar3 == 0) {
      (**(code **)*piVar4)(uVar2);
      LOCK();
      iVar3 = piVar4[2] + -1;
      piVar4[2] = iVar3;
      UNLOCK();
      if (iVar3 == 0) {
        (**(code **)(*piVar4 + 4))();
      }
    }
  }
  if (in_ECX[0xd9] != 0) {
    FUN_004c7db0();
    in_ECX[0xd9] = 0;
  }
  local_14 = in_ECX + 0x59;
  local_18 = 0x80;
  do {
    iVar3 = *local_14;
    if (iVar3 != 0) {
      FUN_007be5f0();
      if (*(int **)(iVar3 + 0x28) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + 0x28) + 0x10))();
        if (*(int **)(iVar3 + 0x28) != (int *)0x0) {
          (**(code **)(**(int **)(iVar3 + 0x28) + 8))();
          *(undefined4 *)(iVar3 + 0x28) = 0;
        }
      }
      FUN_0089120c(iVar3);
      *local_14 = 0;
    }
    local_14 = local_14 + 1;
    local_18 = local_18 + -1;
  } while (local_18 != 0);
  local_8._0_1_ = 6;
  FUN_005540c0(*(undefined4 *)in_ECX[0xfd],(undefined4 *)in_ECX[0xfd]);
  FUN_0089120c(in_ECX[0xfd]);
  local_8._0_1_ = 7;
  FUN_004ca160(*(undefined4 *)in_ECX[0xdf],(undefined4 *)in_ECX[0xdf]);
  iVar3 = FUN_0089120c(in_ECX[0xdf]);
  local_8._0_1_ = 1;
  piVar4 = (int *)in_ECX[0x58];
  if (piVar4 != (int *)0x0) {
    piVar1 = piVar4 + 1;
    LOCK();
    iVar5 = *piVar1;
    iVar3 = *piVar1;
    *piVar1 = iVar5 + -1;
    UNLOCK();
    if (iVar5 + -1 == 0) {
      iVar3 = (**(code **)*piVar4)();
      LOCK();
      iVar5 = piVar4[2] + -1;
      piVar4[2] = iVar5;
      UNLOCK();
      if (iVar5 == 0) {
        iVar3 = (**(code **)(*piVar4 + 4))();
      }
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  in_ECX[0x3c] = CFSM<FSM,CActorState>::vftable;
  piVar4 = in_ECX + 0x3d;
  iVar5 = 0x19;
  do {
    if ((undefined4 *)*piVar4 != (undefined4 *)0x0) {
      iVar3 = (*(code *)**(undefined4 **)*piVar4)(1);
      *piVar4 = 0;
    }
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  in_ECX[0x56] = 0;
  *in_ECX = CBasicObject::vftable;
  ExceptionList = local_10;
  return iVar3;
}

