
undefined4 FUN_00860650(void)

{
  char cVar1;
  char *in_EAX;
  char *pcVar2;
  int unaff_EDI;
  undefined1 local_2c [12];
  undefined4 uStack_20;
  int local_1c;
  undefined1 **local_18;
  undefined1 *puStack_14;
  undefined1 *local_8;
  
  local_8 = local_2c;
  local_18 = (undefined1 **)0xf;
  local_1c = 0;
  local_2c[0] = 0;
  pcVar2 = in_EAX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EAX,(int)pcVar2 - (int)(in_EAX + 1));
  FUN_008608d0(*(undefined4 *)(unaff_EDI + 0x78),*(undefined4 *)(unaff_EDI + 0x7c));
  if (local_8 != *(undefined1 **)(unaff_EDI + 0x7c)) {
    puStack_14 = local_8;
    local_18 = &local_8;
    uStack_20 = 0x8606ad;
    local_1c = unaff_EDI + 0x78;
    FUN_00872f20();
    return 1;
  }
  return 0;
}

