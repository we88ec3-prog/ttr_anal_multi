
/* WARNING: Removing unreachable block (ram,0x00719f34) */
/* WARNING: Removing unreachable block (ram,0x00719f3d) */
/* WARNING: Removing unreachable block (ram,0x00719f42) */
/* WARNING: Removing unreachable block (ram,0x00719f53) */
/* WARNING: Removing unreachable block (ram,0x00719f5a) */

void FUN_00719f10(undefined4 param_1,char *param_2)

{
  char cVar1;
  undefined4 in_EAX;
  char *pcVar2;
  undefined1 *unaff_ESI;
  
  FUN_0071baa0(in_EAX);
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *unaff_ESI = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  return;
}

