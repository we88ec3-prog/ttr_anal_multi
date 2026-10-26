
void FUN_0062eb70(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == *(int *)(in_ECX[0x43] + 0x20)) {
    FUN_0062f300();
    return;
  }
  if (iVar1 == *(int *)(in_ECX[0x3f] + 0x20)) {
    FUN_0062ea30(in_ECX);
    return;
  }
  if (iVar1 == *(int *)(in_ECX[0x41] + 0x20)) {
                    /* WARNING: Could not recover jumptable at 0x0062ebb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0xd4))();
    return;
  }
  if (iVar1 == *(int *)(in_ECX[0x40] + 0x20)) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf438e;
    }
    uVar4 = 0x196;
    FUN_005854b0(0x196,puVar2);
    uVar4 = FUN_00585330(uVar4);
    uVar3 = 0x1e;
    FUN_005854b0(0x1e,uVar4);
    uVar4 = FUN_00585330(uVar3);
    FUN_00404b10(0xcf,uVar4);
  }
  return;
}

