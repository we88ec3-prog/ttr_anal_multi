
/* WARNING: Removing unreachable block (ram,0x008fb72b) */
/* WARNING: Removing unreachable block (ram,0x008fb6eb) */

int FUN_008fb610(void)

{
  char cVar1;
  int iVar2;
  undefined4 local_c;
  
  iVar2 = FUN_008b97e0();
  if ((iVar2 == 0) && (iVar2 = FUN_008bab70(), iVar2 == 0)) {
    if (((char)local_c == '\x1f') &&
       ((((char)(local_c >> 8) == -0x75 && (local_c._2_1_ == '\b')) && ((local_c & 0xe0000000) == 0)
        ))) {
      iVar2 = FUN_008b9820();
      if (((local_c & 0x4000000) == 0) ||
         ((FUN_008b9b20(), iVar2 == 0 && (iVar2 = FUN_008b9820(), iVar2 == 0)))) {
        if ((local_c & 0x8000000) != 0) {
          cVar1 = FUN_008b9a40();
          if (iVar2 != 0) {
            return iVar2;
          }
          while (cVar1 != '\0') {
            cVar1 = FUN_008b9a40();
          }
        }
        if ((local_c & 0x10000000) != 0) {
          cVar1 = FUN_008b9a40();
          if (iVar2 != 0) {
            return iVar2;
          }
          while (cVar1 != '\0') {
            cVar1 = FUN_008b9a40();
          }
        }
        if ((local_c & 0x2000000) != 0) {
          iVar2 = FUN_008b9820();
          return iVar2;
        }
      }
    }
    else {
      iVar2 = 3;
    }
  }
  return iVar2;
}

