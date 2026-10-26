
void FUN_008ecb10(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int in_ECX;
  uint in_EDX;
  
  switch(in_EDX & 0xc0) {
  case 0:
    in_EAX = in_EAX / 2;
    break;
  case 0x40:
  case 0xc0:
    break;
  case 0x80:
    in_EAX = in_EAX * 2;
    break;
  default:
    goto switchD_008ecb28_default;
  }
  *(int *)(in_ECX + 0x1dc) = in_EAX;
switchD_008ecb28_default:
  switch(in_EDX & 0x30) {
  case 0:
    *(undefined4 *)(in_ECX + 0x1e0) = 0;
    goto switchD_008ecb4f_default;
  case 0x10:
    iVar1 = *(int *)(in_ECX + 0x1dc);
    break;
  case 0x20:
    iVar1 = *(int *)(in_ECX + 0x1dc) / 2;
    goto LAB_008ecb89;
  case 0x30:
    iVar1 = *(int *)(in_ECX + 0x1dc) * 3;
    break;
  default:
    goto switchD_008ecb4f_default;
  }
  iVar1 = (int)(iVar1 + (iVar1 >> 0x1f & 3U)) >> 2;
LAB_008ecb89:
  *(int *)(in_ECX + 0x1e0) = iVar1;
switchD_008ecb4f_default:
  iVar1 = *(int *)(in_ECX + 0x1dc);
  if ((in_EDX & 0xf) == 0) {
    iVar2 = iVar1 + -1;
  }
  else {
    iVar2 = ((in_EDX & 0xf) - 4) * iVar1;
    iVar2 = (int)(iVar2 + (iVar2 >> 0x1f & 7U)) >> 3;
  }
  *(int *)(in_ECX + 0x1e4) = iVar2;
  *(int *)(in_ECX + 0x1dc) = (int)(iVar1 + (iVar1 >> 0x1f & 0xffU)) >> 8;
  *(int *)(in_ECX + 0x1e0) =
       (int)(*(int *)(in_ECX + 0x1e0) + (*(int *)(in_ECX + 0x1e0) >> 0x1f & 0xffU)) >> 8;
  *(int *)(in_ECX + 0x1e4) =
       (int)(*(int *)(in_ECX + 0x1e4) + (*(int *)(in_ECX + 0x1e4) >> 0x1f & 0xffU)) >> 8;
  return;
}

