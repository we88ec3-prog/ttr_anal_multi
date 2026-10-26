
undefined4 FUN_008d08d0(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined4 *unaff_EBX;
  char *unaff_ESI;
  
  pcVar2 = (char *)*unaff_EBX;
  pcVar1 = pcVar2 + 3;
  if ((((pcVar1 < unaff_ESI) && (*pcVar2 == 't')) && (pcVar2[1] == 'r')) &&
     ((pcVar2[2] == 'u' && (*pcVar1 == 'e')))) {
    *unaff_EBX = pcVar2 + 5;
    return 1;
  }
  if ((((pcVar2 + 4 < unaff_ESI) && ((*pcVar2 == 'f' && (pcVar2[1] == 'a')))) && (pcVar2[2] == 'l'))
     && ((*pcVar1 == 's' && (pcVar2[4] == 'e')))) {
    pcVar2 = pcVar2 + 6;
  }
  *unaff_EBX = pcVar2;
  return 0;
}

