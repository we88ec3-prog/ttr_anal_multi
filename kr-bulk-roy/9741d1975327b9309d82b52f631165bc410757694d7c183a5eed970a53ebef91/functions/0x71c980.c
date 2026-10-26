
void FUN_0071c980(void *param_1,int param_2)

{
  float fVar1;
  char cVar2;
  char *_String;
  double *in_ECX;
  uint _Size;
  double dVar3;
  char local_28 [32];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  _Size = param_2 - (int)param_1;
  _String = local_28;
  if (0x1f < _Size) {
    _String = (char *)(*(code *)PTR_FUN_00d63d48)(_Size + 1);
    if (_String == (char *)0x0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  FID_conflict__memcpy(_String,param_1,_Size);
  _String[_Size] = '\0';
  cVar2 = FUN_0071c8a0();
  if (cVar2 == '\0') {
    fVar1 = NAN;
  }
  else {
    dVar3 = _atof(_String);
    fVar1 = (float)dVar3;
  }
  *in_ECX = (double)fVar1;
  if (_String != local_28) {
    (*(code *)PTR_FUN_00d63d4c)(_String);
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

