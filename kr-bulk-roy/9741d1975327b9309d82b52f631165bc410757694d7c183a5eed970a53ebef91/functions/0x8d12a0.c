
int FUN_008d12a0(void)

{
  int iVar1;
  size_t unaff_EBX;
  int iVar2;
  char *unaff_EDI;
  
  iVar2 = 0;
  do {
    if (*(&PTR_s_Ascender_00be7d38)[iVar2] == *unaff_EDI) {
      for (; iVar2 < 0x4a; iVar2 = iVar2 + 1) {
        if (*(&PTR_s_Ascender_00be7d38)[iVar2] != *unaff_EDI) {
          return 0x4b;
        }
        iVar1 = _strncmp((&PTR_s_Ascender_00be7d38)[iVar2],unaff_EDI,unaff_EBX);
        if (iVar1 == 0) {
          return iVar2;
        }
      }
    }
    iVar2 = iVar2 + 1;
    if (0x49 < iVar2) {
      return 0x4b;
    }
  } while( true );
}

