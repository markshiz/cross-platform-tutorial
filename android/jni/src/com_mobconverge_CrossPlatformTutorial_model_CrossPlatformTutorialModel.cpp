
#include <cross_platform_model.h>
#include <cross_platform_database_acquire.h>
#include "com_mobconverge_CrossPlatformTutorial_model_CrossPlatformTutorialModel_Person.h"
#include "log.h"

extern "C" {

  JNIEXPORT jobjectArray JNICALL Java_com_mobconverge_CrossPlatformTutorial_model_CrossPlatformTutorialModel_getAllPersons
    (JNIEnv *env, jobject) {

    static jclass personClass = NULL;
    static jmethodID constructor = NULL;

    if (personClass == NULL) {
      personClass = env->FindClass("com/mobconverge/CrossPlatformTutorial/model/CrossPlatformTutorialModel$Person");
      if (!personClass) {
        LOGV("Class not found!");
        return NULL;
      }
    }

    if (constructor == NULL) {
      constructor = env->GetMethodID(personClass, "<init>", "(ILjava/lang/String;Ljava/lang/String;)V");
      if (!constructor) {
        LOGV("Constructor not found!");
        return NULL;
      }
    }

    Person::container_t allPeople = getAllPersons();  

    LOGV("Retreived all persons");

    jobjectArray result = env->NewObjectArray(allPeople.size(), personClass, NULL);

    for (Person::container_t::iterator it = allPeople.begin(); it != allPeople.end(); ++it ) {
        LOGV("Placing %s %s",it->getFirstName().getAsCString(), it->getLastName().getAsCString());

        jstring fname = env->NewStringUTF(it->getFirstName().getAsCString()), 
                lname = env->NewStringUTF(it->getLastName().getAsCString());
        jobject obj = env->NewObject(personClass, constructor, it->getID(), fname, lname);

        env->SetObjectArrayElement(result, std::distance(allPeople.begin(), it), obj);
    }

    return result;
  }

}

