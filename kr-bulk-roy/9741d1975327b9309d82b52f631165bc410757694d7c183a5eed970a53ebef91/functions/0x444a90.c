
void FUN_00444a90(void)

{
  if ((DAT_00fb7c18 & 1) == 0) {
    DAT_00fb7c18 = DAT_00fb7c18 | 1;
    FUN_004449d0();
    return;
  }
  return;
}

