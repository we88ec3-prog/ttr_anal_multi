
void FUN_006d6350(void)

{
  code *pcVar1;
  int *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  iVar3 = *in_EAX;
  if (iVar3 != 0) {
    puVar2 = (undefined4 *)(iVar3 + 0xc);
    if (0xf < *(uint *)(iVar3 + 0x20)) {
      puVar2 = (undefined4 *)*puVar2;
    }
    iVar3 = FUN_00495610(DAT_00fb1318,puVar2,0);
    if (iVar3 == 0) {
      FUN_006ded00(&DAT_00c40ac4);
      local_8 = 0x181;
      iVar3 = FUN_005854b0();
      FUN_005740f0(&local_8);
      if (local_c != *(int *)(iVar3 + 4)) {
        puVar2 = (undefined4 *)(local_c + 0x10);
        if (7 < *(uint *)(local_c + 0x24)) {
          puVar2 = (undefined4 *)*puVar2;
        }
        FUN_00404b10(0xca,puVar2,&DAT_00bed1fc,0,0);
        return;
      }
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    (**(code **)(*(int *)*in_EAX + 0x2c))();
  }
  return;
}

