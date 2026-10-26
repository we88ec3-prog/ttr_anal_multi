
void FUN_00781e50(void)

{
  undefined4 *in_EAX;
  int unaff_EDI;
  undefined4 *puVar1;
  undefined4 local_c [2];
  
  puVar1 = local_c;
  local_c[0] = in_EAX[4];
  FUN_00721910(*(undefined4 *)(unaff_EDI + 0x88),puVar1,4,0);
  if (0xf < (uint)in_EAX[5]) {
    in_EAX = (undefined4 *)*in_EAX;
  }
  if ((in_EAX != (undefined4 *)0x0) && (puVar1 != (undefined4 *)0x0)) {
    FUN_00721910(*(undefined4 *)(unaff_EDI + 0x88),in_EAX,puVar1,0);
  }
  return;
}

