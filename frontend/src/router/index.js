import Vue from 'vue'
import VueRouter from 'vue-router'

Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'HomePage',
    component: () => import('../views/Home.vue')
  },
  {
    path: '/home',
    name: 'HomePage',
    component: () => import('../views/Home.vue')
  },
  {
    path: '/history',
    name: 'HistoryPage',
    component: () => import('../views/History.vue')
  },
  {
    path: '/specification',
    name: 'NotificationPage',
    component: () => import('../views/Notification&History.vue')
  },
  {
    path: '/profile',
    name: 'ProfilePage',
    component: () => import('../views/Profile.vue')
  },
  {
    path: '/user/login',
    name: 'Login',
    component: () => import('../views/user/Login.vue')
  },
  {
    path: '/user/signup',
    name: 'Signup',
    component: () => import('../views/user/Signup.vue')
  },
  
]

const router = new VueRouter({
  mode: 'history',
  routes
})

export default router