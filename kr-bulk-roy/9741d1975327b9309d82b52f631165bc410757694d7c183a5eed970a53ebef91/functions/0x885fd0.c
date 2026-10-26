
/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Multiple Matches With Same Base Name
    int __cdecl std::_Getloctxt<unsigned short,class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >(class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > &,class std::istreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > &,unsigned int,unsigned short const *)
    int __cdecl std::_Getloctxt<wchar_t,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >(class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,class std::istreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > &,unsigned int,wchar_t const *)
   
   Library: Visual Studio 2010 Release */

void _Getloctxt<>(int param_1,undefined4 param_2,uint param_3,short *param_4)

{
  bool bVar1;
  char cVar2;
  short sVar3;
  undefined4 ****ppppuVar4;
  undefined1 uVar5;
  int iVar7;
  uint uVar8;
  uint local_38;
  undefined4 ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  uint uVar6;
  
  uStack_4 = 0x34;
  local_8 = 0x885fdc;
  iVar7 = 0;
  sVar3 = *param_4;
  while (sVar3 != 0) {
    if (sVar3 == *param_4) {
      param_3 = param_3 + 1;
    }
    iVar7 = iVar7 + 1;
    sVar3 = param_4[iVar7];
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = (undefined4 ***)((uint)local_30[0] & 0xffffff00);
  FUN_0046e1b0(param_3,0);
  local_8 = 0;
  local_38 = 1;
  while( true ) {
    iVar7 = 0;
    uVar8 = 0;
    bVar1 = false;
    if (param_3 == 0) break;
    do {
      sVar3 = param_4[iVar7];
      if (sVar3 != 0) {
        do {
          if (sVar3 == *param_4) break;
          iVar7 = iVar7 + 1;
          sVar3 = param_4[iVar7];
        } while (sVar3 != 0);
      }
      ppppuVar4 = (undefined4 ****)local_30[0];
      if (local_1c < 0x10) {
        ppppuVar4 = local_30;
      }
      if (*(char *)((int)ppppuVar4 + uVar8) == '\0') {
        iVar7 = iVar7 + local_38;
        if ((param_4[iVar7] == *param_4) || (param_4[iVar7] == 0)) {
          uVar6 = 0x7f;
          if (local_38 < 0x7f) {
            uVar6 = local_38;
          }
          uVar5 = (undefined1)uVar6;
          ppppuVar4 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar4 = local_30;
          }
        }
        else {
          cVar2 = equal(param_2);
          if (cVar2 == '\0') {
            if (*(char *)(param_1 + 4) == '\0') {
              Peek();
            }
            if (param_4[iVar7] == *(short *)(param_1 + 6)) {
              bVar1 = true;
              goto LAB_008860fe;
            }
          }
          uVar6 = local_38;
          if (0x7e < local_38) {
            uVar6 = 0x7f;
          }
          uVar5 = (undefined1)uVar6;
          ppppuVar4 = (undefined4 ****)local_30[0];
          if (local_1c < 0x10) {
            ppppuVar4 = local_30;
          }
        }
        *(undefined1 *)((int)ppppuVar4 + uVar8) = uVar5;
      }
      else {
        ppppuVar4 = (undefined4 ****)local_30[0];
        if (local_1c < 0x10) {
          ppppuVar4 = local_30;
        }
        iVar7 = iVar7 + *(char *)((int)ppppuVar4 + uVar8);
      }
LAB_008860fe:
      uVar8 = uVar8 + 1;
    } while (uVar8 < param_3);
    if ((!bVar1) || (cVar2 = equal(param_2), cVar2 != '\0')) break;
    local_38 = local_38 + 1;
    Inc();
  }
  FUN_00402f30(1,0);
  FUN_0089dbbc();
  return;
}

